/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:29 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/18 21:02:22 by cwoon            ###   ########.fr       */
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

typedef struct s_philo {
	pthread_t	*thread;
	int	which;
	// int	i_first;
	// int	i_last;
	int	total;
	pthread_mutex_t	*forks;
	int	total_forks;
}	t_philo;

typedef struct s_status {
	int	die_at;
	int	eat_at;
	int	think_at;
	// int	death;
}	t_status;

typedef struct s_data {
	t_philo	*philo;
	t_status	*status;
	int	total_meals;
}	t_data;

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
