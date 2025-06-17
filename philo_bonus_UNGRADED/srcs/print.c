/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:39:46 by cwoon             #+#    #+#             */
/*   Updated: 2025/06/17 19:27:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_action(t_philo *philo, t_status status);
void	print_status(t_philo *philo, char *str, t_status status);

void	print_action(t_philo *philo, t_status status)
{
	sem_wait(philo->table->sem_print);
	if (is_exit_simulation(philo->table) && status != DIED)
	{
		sem_post(philo->table->sem_print);
		return ;
	}
	if (status == DIED)
	{
		sem_wait(philo->table->sem_is_dead);
		if (!philo->table->has_dead_philo)
		{
			philo->table->has_dead_philo += 1;
			print_status(philo, "died", status);
			cleanup(philo->table, YES);
		}
		sem_post(philo->table->sem_is_dead);
	}
	else if (status == EATING)
	{
		print_status(philo, "is eating", status);
		sem_wait(philo->table->sem_meals_required);
		philo->meals_required -= 1;
		sem_post(philo->table->sem_meals_required);
		if (philo->meals_required == 0)
		{
			sem_post(philo->table->sem_print);
			sem_post(philo->table->sem_forks);
			sem_post(philo->table->sem_forks);
			printf("full meal\n");
			kill(philo->pid, SIGKILL);
			exit(0);
		}
	}
	else if (status == SLEEPING)
		print_status(philo, "is sleeping", status);
		else if (status == THINKING)
		print_status(philo, "is thinking", status);
		else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork", status);
	sem_post(philo->table->sem_print);
}

void	print_status(t_philo *philo, char *str, t_status status)
{
	const char	*status_colour;

	status_colour = COLOUR;
	if (status == DIED)
		status_colour = RED;
	else if (status == EATING)
		status_colour = GREEN;
	else if (status == SLEEPING)
		status_colour = PURPLE;
	else if (status == THINKING)
		status_colour = YELLOW;
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		status_colour = CYAN;
	printf("%ld\t" BLUE "%d\t" COLOUR "%s%s\n" COLOUR, \
	get_time_in_ms() - philo->table->timer, philo->id + 1, status_colour, str);
}
