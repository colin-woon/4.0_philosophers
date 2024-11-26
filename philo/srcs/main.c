/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:48 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/26 18:51:24 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_join(table->philo[0].thread, NULL);
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
	// TEST_CHECK_INIT(&table);
	cleanup(&table);
}
