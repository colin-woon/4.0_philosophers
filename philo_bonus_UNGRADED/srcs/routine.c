/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:56 by cwoon             #+#    #+#             */
/*   Updated: 2025/06/17 17:53:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philo *philo);
void	lonely_philo(t_philo *philo);
void	eat_routine(t_philo *philo);
void	sleep_think_routine(t_philo *philo);
void	monitor_routine(t_philo *philo);
int		is_dead(t_philo *philo);

void	routine(t_philo *philo)
{
	if (philo->table->total_philos == 1)
		return (lonely_philo(philo));
	else
	{
		philo->pid = fork();
		if (philo->pid == 0)
			monitor_routine(philo);
	}
	if (philo->id % 2)
		waiting(philo->table, philo->table->time_to_sleep);
	while (!is_exit_simulation(philo->table))
	{
		eat_routine(philo);
		if (is_exit_simulation(philo->table))
			exit(EXIT_SUCCESS);
		sleep_think_routine(philo);
	}
}

void	lonely_philo(t_philo *philo)
{
	sem_wait(philo->table->sem_forks);
	print_action(philo, GOT_FORK_1);
	waiting(philo->table, philo->table->time_to_die);
	print_action(philo, DIED);
	sem_post(philo->table->sem_forks);
}

void	eat_routine(t_philo *philo)
{
	sem_wait(philo->table->sem_forks);
	sem_wait(philo->table->sem_forks);
	print_action(philo, GOT_FORK_1);
	print_action(philo, GOT_FORK_2);
	print_action(philo, EATING);
	sem_wait(philo->table->sem_last_meal);
	philo->last_meal = get_time_in_ms();
	sem_post(philo->table->sem_last_meal);
	waiting(philo->table, philo->table->time_to_eat);
	sem_wait(philo->table->sem_meals_required);
	philo->meals_required -= 1;
	sem_post(philo->table->sem_meals_required);
	sem_post(philo->table->sem_forks);
	sem_post(philo->table->sem_forks);
}

void	sleep_think_routine(t_philo *philo)
{
	print_action(philo, SLEEPING);
	waiting(philo->table, philo->table->time_to_sleep);
	print_action(philo, THINKING);
}

void	monitor_routine(t_philo *philo)
{
	while (!is_exit_simulation(philo->table))
	{
		usleep(100);
		sem_wait(philo->table->sem_meals_required);
		if (philo->meals_required == 0)
		{
			sem_wait(philo->table->sem_is_exit);
			philo->table->is_exit = 1;
			sem_post(philo->table->sem_is_exit);
			sem_post(philo->table->sem_meals_required);
			break ;
		}
		sem_post(philo->table->sem_meals_required);
		if (is_dead(philo))
		{
			// cleanup(philo->table, YES);
			break ;
		}
	}
}

int	is_dead(t_philo *philo)
{
	sem_wait(philo->table->sem_last_meal);
	// printf("ID:%d CHECKING: %ld\n", philo->id, get_time_in_ms() - philo->last_meal);
	if (get_time_in_ms() - philo->last_meal >= philo->table->time_to_die)
	{
		sem_wait(philo->table->sem_is_exit);
		philo->table->is_exit = 1;
		sem_post(philo->table->sem_is_exit);
		print_action(philo, DIED);
		sem_post(philo->table->sem_last_meal);
		return (1);
	}
	sem_post(philo->table->sem_last_meal);
	return (0);
}

