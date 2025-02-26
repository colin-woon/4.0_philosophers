/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:26 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/26 17:16:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	handle_error(t_table *table, int error_num);
void	cleanup(t_table *table, int is_someone_dead);

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
		cleanup(table, NO);
	exit(EXIT_FAILURE);
}

void	cleanup(t_table *table, int is_someone_dead)
{
	cleanup_semaphores(table);
	if (is_someone_dead)
		kill(0, SIGKILL);
	else
	{
		while(waitpid(-1, NULL, WUNTRACED) != -1)
			;
	}
}


