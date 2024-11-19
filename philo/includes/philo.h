/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:29 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/19 15:07:11 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

# define ARG_ERROR -1
# define MAX_PHILO 200

typedef struct s_philo {
	pthread_t	thread;
	int	id;
	int	nth_meal;
	int fork[2];
	time_t	last_meal;
	// pthread_mutex_t	*forks;
	// int	total_forks;
}	t_philo;


typedef struct s_table {
	int	total_philos;
	int	die_at;
	int	eat_at;
	int	think_at;
	int	total_meals;
	t_philo	philo[MAX_PHILO];
	pthread_t	monitor;
	int	timestamp
}	t_table;

// Error Handling

void	clean(t_data *data);
void	wash_forks(t_philo *philo);
void	handle_error(t_data *data, int error_num);

// Utils libft

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);

#endif
