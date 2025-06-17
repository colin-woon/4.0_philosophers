/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_semaphore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:02:05 by cwoon             #+#    #+#             */
/*   Updated: 2025/06/13 17:47:10 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	my_sem_remove(sem_t *sem, char *sem_file);
void	cleanup_semaphores(t_table *table);

void	my_sem_remove(sem_t *sem, char *sem_file)
{
	sem_close(sem);
	sem_unlink(sem_file);
}

void	cleanup_semaphores(t_table *table)
{
	if (table->sem_print)
		my_sem_remove(table->sem_print, PRINT_SEM);
	if (table->sem_is_dead)
		my_sem_remove(table->sem_is_dead, IS_DEAD_SEM);
	if (table->sem_is_exit)
		my_sem_remove(table->sem_is_exit, IS_EXIT_SEM);
	if (table->sem_global)
		my_sem_remove(table->sem_global, GLOBAL_SEM);
	if (table->sem_eat_routine)
		my_sem_remove(table->sem_eat_routine, EAT_ROUTINE_SEM);
	if (table->sem_forks)
		my_sem_remove(table->sem_forks, FORKS_SEM);
	if (table->sem_last_meal)
		my_sem_remove(table->sem_last_meal, LAST_MEAL_SEM);
	if (table->sem_meals_required)
		my_sem_remove(table->sem_meals_required, MEALS_REQUIRED_SEM);
}

