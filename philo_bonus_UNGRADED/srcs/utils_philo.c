/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:44:44 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 15:39:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	get_time_in_ms(void);
void	waiting(t_table *table, time_t waiting_time);
int		is_exit_simulation(t_table *table);
int		is_dead(t_philo *philo);

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	waiting(t_table *table, time_t waiting_time)
{
	time_t	time_to_wakeup;

	time_to_wakeup = get_time_in_ms() + waiting_time;
	while (get_time_in_ms() < time_to_wakeup)
	{
		if (is_exit_simulation(table))
			break ;
		usleep(100);
	}
}

int	is_exit_simulation(t_table *table)
{
	int	status;

	status = 0;
	sem_wait(table->sem_is_exit);
	if (table->is_exit == 1)
		status = 1;
	sem_post(table->sem_is_exit);
	return (status);
}

int	is_dead(t_philo *philo)
{
	sem_wait(philo->table->sem_eat_routine);
	if (get_time_in_ms() - philo->last_meal >= philo->table->time_to_die)
	{
		print_action(philo, DIED);
		sem_wait(philo->table->sem_is_exit);
		philo->table->is_exit = 1;
		sem_post(philo->table->sem_is_exit);
		sem_post(philo->table->sem_eat_routine);
		return (1);
	}
	sem_post(philo->table->sem_eat_routine);
	return (0);
}
