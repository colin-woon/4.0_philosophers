/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:48 by cwoon             #+#    #+#             */
/*   Updated: 2024/12/02 17:44:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulate(t_table *table);
void	exit_simulation(t_table *table);

void	simulate(t_table *table)
{
	int	i;

	i = 0;
	table->timer = get_time_in_ms();
	while (i < table->total_philos)
	{
		if (pthread_create(&table->philo[i].thread, NULL, routine, (void *)&table->philo[i]) != 0)
			return (handle_error(table, THREAD_ERROR));
		i++;
	}
}

void	exit_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
		pthread_join(table->philo[i++].thread, NULL);
	if (table->total_philos > 1)
		pthread_join(table->monitor, NULL);
	cleanup(table);
}

int main(int ac, char **av)
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
	// TEST_CHECK_INIT(&table);
}
