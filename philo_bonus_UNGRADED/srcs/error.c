/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:26 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 15:05:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	handle_error(t_table *table, int error_num);
void	cleanup(t_table *table);

void	handle_error(t_table *table, int error_num)
{
	if (error_num == ARG_ERROR)
		ft_putendl_fd(ERR_MSG_ARG, STDERR_FILENO);
	if (error_num == FORMAT_ERROR)
		ft_putendl_fd(ERR_MSG_FORMAT, STDERR_FILENO);
	if (error_num == MALLOC_ERROR)
		ft_putendl_fd(ERR_MSG_MALLOC, STDERR_FILENO);
	if (error_num == MUTEX_ERROR)
		ft_putendl_fd(ERR_MSG_MUTEX, STDERR_FILENO);
	if (table)
		cleanup(table);
	exit(EXIT_FAILURE);
}

void	cleanup(t_table *table)
{
	if (table->sem_print)
		my_sem_remove(table->sem_print, PRINT_SEM);
	if (table->sem_is_dead)
		my_sem_remove(table->sem_is_dead, IS_DEAD_SEM);
	if (table->sem_is_exit)
		my_sem_remove(table->sem_is_exit, IS_EXIT_SEM);
	if (table->sem_global)
		my_sem_remove(table->sem_global, GLOBAL_SEM);
	if (table->sem_forks)
			my_sem_remove(table->sem_forks, FORKS_SEM);
}

