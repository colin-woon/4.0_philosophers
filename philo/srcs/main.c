/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:48 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/19 21:40:16 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac != 5 && ac != 6)
		handle_error(ARG_ERROR);
	if (parse_args(ac, av) == 0)
		handle_error(FORMAT_ERROR);
	initialize(table);
}
