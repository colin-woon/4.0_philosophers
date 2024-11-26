/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:48 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/25 21:18:45 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		handle_error(NULL, ARG_ERROR);
	if (parse_args(ac, av) == 0)
		handle_error(NULL, FORMAT_ERROR);
	initialize(&table, ac, av);
	// TEST_CHECK_INIT(&table);
	cleanup(&table);
}
