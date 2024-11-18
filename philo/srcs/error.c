/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:26 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/18 21:11:36 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_data *data);
void	wash_forks(t_philo *philo);
void	handle_error(t_data *data, int error_num);

void	handle_error(t_data *data, int error_num)
{
	if (data)
		clean(data);
	if (error_num == ARG_ERROR)
		ft_putendl_fd("Error: Incorrect arguments", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	clean(t_data *data)
{
	if (data->philo)
	{
		if (data->philo->thread)
			free(data->philo->thread);
		if (data->philo->forks)
			wash_forks(data->philo);
		free(data->philo);
	}
	if (data->status)
		free(data->status);
}

void	wash_forks(t_philo *philo)
{
	int i = 0;
	while (i < philo->total_forks)
		pthread_mutex_destroy(&philo->forks[i++]);
	free(philo->forks);
}
