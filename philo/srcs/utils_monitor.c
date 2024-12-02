/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:25:07 by cwoon             #+#    #+#             */
/*   Updated: 2024/12/02 17:20:17 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		has_finished_meals(t_table *table);
void	set_is_exit(t_table *table, int status);
int		is_dead(t_philo *philo);

int	has_finished_meals(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_mutex_lock(&table->lock_monitor);
		if (is_dead(&table->philo[i]))
		{
			set_is_exit(table, 1);
			pthread_mutex_unlock(&table->lock_monitor);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->lock_monitor);
	return (0);
}

void	set_is_exit(t_table *table, int status)
{
	pthread_mutex_lock(&table->lock_is_exit);
	table->is_exit = status;
	pthread_mutex_unlock(&table->lock_is_exit);
}

int	is_dead(t_philo *philo)
{
	// printf("HELLO\n");
	if (get_time_in_ms() - philo->last_meal >= philo->table->time_to_die)
	{
		print_action(philo, DIED);
		return (1);
	}
	return (0);
}
