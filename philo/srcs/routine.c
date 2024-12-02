/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:56 by cwoon             #+#    #+#             */
/*   Updated: 2024/12/02 15:35:52 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data);
void	*lonely_philo(t_philo *philo);
void	eat_routine(t_philo *philo);
void	sleep_think_routine(t_philo *philo);

void	*routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->lock_eat_routine);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->lock_eat_routine);
	if (philo->table->total_philos == 1)
		return (lonely_philo(philo));
	if (philo->id % 2)
		waiting(philo->table, philo->table->time_to_sleep);
	while (1)
	{
		eat_routine(philo);
		sleep_think_routine(philo);
	}
	return(NULL);
}

void	*lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_forks[philo->fork[0]]);
	print_action(philo, GOT_FORK_1);
	waiting(philo->table, philo->table->time_to_die);
	print_action(philo, DIED);
	pthread_mutex_unlock(&philo->table->lock_forks[philo->fork[0]]);
	return(NULL);
}

void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_forks[philo->fork[0]]);
	print_action(philo, GOT_FORK_1);
	pthread_mutex_lock(&philo->table->lock_forks[philo->fork[1]]);
	print_action(philo, GOT_FORK_2);
	print_action(philo, EATING);
	pthread_mutex_lock(&philo->lock_eat_routine);
	philo->last_meal = get_time_in_ms();
	waiting(philo->table, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->lock_eat_routine);
	philo->meals_ate += 1;
	pthread_mutex_unlock(&philo->table->lock_forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->lock_forks[philo->fork[0]]);
}

void	sleep_think_routine(t_philo *philo)
{
	print_action(philo, SLEEPING);
	waiting(philo->table, philo->table->time_to_sleep);
	print_action(philo, THINKING);
}
