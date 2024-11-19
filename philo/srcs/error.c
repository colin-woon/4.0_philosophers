/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:26 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/19 21:00:05 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	clean(t_table *table, t_philo *philo);
// void	wash_forks(t_philo *philo);
void	handle_error(int error_num);

void	handle_error(int error_num)
{
	if (error_num == ARG_ERROR)
		ft_putendl_fd(ERR_MSG_ARG, STDERR_FILENO);
	if (error_num == FORMAT_ERROR)
		ft_putendl_fd(ERR_MSG_FORMAT, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// void	clean(t_table *table, t_philo *philo)
// {
// 	if (table->philo)
// 		free(table->philo);
// 	if (philo->table)
// 		free(philo->table);
// }

// void	wash_forks(t_philo *philo)
// {
// 	int i = 0;
// 	while (i < philo->total_forks)
// 		pthread_mutex_destroy(&philo->forks[i++]);
// 	free(philo->forks);
// }
