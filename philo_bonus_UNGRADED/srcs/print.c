/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:39:46 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 15:03:53 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_action(t_philo *philo, t_status status);
void	print_status(t_philo *philo, char *str, t_status status);

void	print_action(t_philo *philo, t_status status)
{
	sem_wait(philo->table->sem_print);
	if (is_exit_simulation(philo->table))
	{
		sem_post(philo->table->sem_print);
		return ;
	}
	if (status == DIED)
		print_status(philo, "died", status);
	else if (status == EATING)
		print_status(philo, "is eating", status);
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
