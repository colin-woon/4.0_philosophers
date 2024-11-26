/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:21:35 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/26 17:03:27 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_table *table, int ac, char **av);
void	initialize_locks(t_table *table);
void	initialize_philo(t_table *table);
void	assign_forks(t_philo *philo, t_table *table);

void	initialize(t_table *table, int ac, char **av)
{
	table->timer = 0;
	table->total_philos = ft_atoi(av[1]);
	table->die_at = ft_atoi(av[2]);
	table->eat_at = ft_atoi(av[3]);
	table->sleep_at = ft_atoi(av[4]);
	table->meals_needed = -1;
	if (ac == 6)
		table->meals_needed = ft_atoi(av[5]);
	table->is_exit = 0;
	initialize_locks(table);
	initialize_philo(table);
}

void	initialize_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philo[i].id = i;
		table->philo[i].meals_ate = 0;
		assign_forks(&table->philo[i], table);
		table->philo[i].last_meal = 0;
		if (pthread_mutex_init(&table->philo[i].lock_last_meal, 0) != 0)
			return (handle_error(table, MUTEX_ERROR));
		table->philo[i].table = table;
		i++;
	}
}

void	initialize_locks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		if (pthread_mutex_init(&table->lock_forks[i], 0) != 0)
			return (handle_error(table, MUTEX_ERROR));
		i++;
	}
	if (pthread_mutex_init(&table->lock_is_exit, 0) != 0)
		return (handle_error(table, MUTEX_ERROR));
}

// if (philo->id % 2)
// {
// 	philo->fork[0] = (philo->id + 1) % philo->table->total_philos;
// 	philo->fork[1] = philo->id;
// }
void	assign_forks(t_philo *philo, t_table *table)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = philo->id + 1 % table->total_philos;
}
