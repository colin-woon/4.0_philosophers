/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:10:31 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/19 21:38:41 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(char *str);
int	parse_args(int ac, char **av);

int	parse_args(int ac, char **av)
{
	int	i;
	int	temp;

	i = 1;
	while (av[i])
	{
		temp = validate_args(av[i]);
		if (i == 1)
		{
			if (temp > 200 || temp == 0)
				return (0);
		}
		if (temp < 0)
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
			result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result);
}
