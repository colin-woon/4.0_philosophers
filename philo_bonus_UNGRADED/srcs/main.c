/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:48 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/26 17:20:55 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	simulate(t_table *table);
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
	cleanup(&table, NO);
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
			sem_wait(table->sem_global);
			if (is_exit_simulation(table) \
				|| is_dead(&table->philo[i]))
					cleanup(table, YES);
				i++;
			sem_post(table->sem_global);
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
		sem_wait(table->sem_eat_routine);
		table->philo[i].last_meal = get_time_in_ms();
		sem_post(table->sem_eat_routine);
		table->pid[i] = fork();
		if (table->pid[i] == 0)
			routine(&table->philo[i]);
		i++;
	}
	if (table->total_philos > 1)
		monitor_death(table);
}
