/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_semaphore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:02:05 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 14:53:30 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	my_sem_remove(sem_t *sem, char *sem_file);

void	my_sem_remove(sem_t *sem, char *sem_file)
{
	sem_close(sem);
	sem_unlink(sem_file);
}
