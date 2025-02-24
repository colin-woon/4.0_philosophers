/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:21:35 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 17:45:43 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initialize(t_table *table, int ac, char **av);
void	initialize_semaphores(t_table *table);
void	initialize_philo(t_table *table);
void	assign_forks(t_philo *philo, t_table *table);

void	initialize(t_table *table, int ac, char **av)
{
	table->timer = 0;
	table->total_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->meals_needed = -1;
	if (ac == 6)
		table->meals_needed = ft_atoi(av[5]);
	table->is_exit = 0;
	table->has_dead_philo = 0;
	memset(table->pid, 0, sizeof(pid_t *));
	initialize_semaphores(table);
	initialize_philo(table);
}

void	initialize_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		table->philo[i].id = i;
		table->philo[i].meals_required = table->meals_needed;
		// assign_forks(&table->philo[i], table);
		table->philo[i].last_meal = 0;
		table->philo[i].table = table;
		i++;
	}
}

void	initialize_semaphores(t_table *table)
{
	cleanup(table);
	table->sem_print = sem_open(PRINT_SEM, O_CREAT, 0644, 1);
	table->sem_is_dead = sem_open(IS_DEAD_SEM, O_CREAT, 0644, 1);
	table->sem_is_exit = sem_open(IS_EXIT_SEM, O_CREAT, 0644, 1);
	table->sem_global = sem_open(GLOBAL_SEM, O_CREAT, 0644, 1);
	table->sem_eat_routine = sem_open(EAT_ROUTINE_SEM, O_CREAT, 0644, 1);
	table->sem_forks = sem_open(FORKS_SEM, O_CREAT, 0644, table->total_philos);
}

// void	assign_forks(t_philo *philo, t_table *table)
// {
// 	philo->fork[0] = philo->id;
// 	philo->fork[1] = (philo->id + 1) % table->total_philos;
// }
