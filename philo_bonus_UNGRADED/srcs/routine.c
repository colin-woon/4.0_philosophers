/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:56 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 18:22:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philo *philo);
void	lonely_philo(t_philo *philo);
void	eat_routine(t_philo *philo);
void	sleep_think_routine(t_philo *philo);

void	routine(t_philo *philo)
{
	if (philo->table->total_philos == 1)
		return (lonely_philo(philo));
	if (philo->id % 2)
		waiting(philo->table, philo->table->time_to_sleep);
	while (!is_exit_simulation(philo->table))
	{
		eat_routine(philo);
		if (philo->meals_required == 0 || is_exit_simulation(philo->table))
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
	sem_wait(philo->table->sem_eat_routine);
	philo->last_meal = get_time_in_ms();
	sem_post(philo->table->sem_eat_routine);
	waiting(philo->table, philo->table->time_to_eat);
	sem_wait(philo->table->sem_global);
	philo->meals_required -= 1;
	// printf("philo %d meals_required %d\n", philo->id, philo->meals_required);
	sem_post(philo->table->sem_global);
	sem_post(philo->table->sem_forks);
	sem_post(philo->table->sem_forks);
}

void	sleep_think_routine(t_philo *philo)
{
	print_action(philo, SLEEPING);
	waiting(philo->table, philo->table->time_to_sleep);
	print_action(philo, THINKING);
}
