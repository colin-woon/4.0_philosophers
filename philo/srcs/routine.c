/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:56 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/26 18:51:11 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data);
void	*lonely_philo(t_philo *philo);

void	*routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->lock_last_meal);
	if (philo->table->total_philos == 1)
		return (lonely_philo(philo));
	return(NULL);
}

void	*lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_forks[philo->fork[0]]);
	action(philo, GOT_FORK_1);
	waiting(philo->table, philo->table->die_at);
	action(philo, DIED);
	pthread_mutex_unlock(&philo->table->lock_forks[philo->fork[0]]);
	return(NULL);
}
