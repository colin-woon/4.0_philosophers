/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:48 by cwoon             #+#    #+#             */
/*   Updated: 2024/12/02 21:53:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulate(t_table *table);
void	exit_simulation(t_table *table);
void	monitor_death(t_table *table);

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		handle_error(NULL, ARG_ERROR);
	if (parse_args(av) == 0)
		handle_error(NULL, FORMAT_ERROR);
	initialize(&table, ac, av);
	simulate(&table);
	exit_simulation(&table);
	return (EXIT_SUCCESS);
}

void	monitor_death(t_table *table)
{
	int	i;
	int	infinite;

	i = 0;
	infinite = 1;
	while (infinite)
	{
		i = 0;
		while (infinite && i < table->total_philos)
		{
			usleep(100);
			if (table->philo->meals_required == 0 \
			|| is_exit_simulation(table) \
			|| is_dead(&table->philo[i]))
			{
				infinite = 0;
				break ;
			}
			i++;
		}
	}
}

void	simulate(t_table *table)
{
	int	i;

	i = 0;
	table->timer = get_time_in_ms();
	while (i < table->total_philos)
	{
		pthread_mutex_lock(&table->philo[i].lock_eat_routine);
		table->philo[i].last_meal = get_time_in_ms();
		pthread_mutex_unlock(&table->philo[i].lock_eat_routine);
		if (pthread_create(&table->philo[i].thread, NULL, routine, \
		(void *)&table->philo[i]) != 0)
			return (handle_error(table, THREAD_ERROR));
		i++;
	}
	if (table->total_philos > 1)
		monitor_death(table);
}

void	exit_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
		pthread_join(table->philo[i++].thread, NULL);
	cleanup(table);
}
