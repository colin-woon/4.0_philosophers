/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:29 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/25 21:05:22 by cwoon            ###   ########.fr       */
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
# define FORMAT_ERROR -2
# define MALLOC_ERROR -3
# define MUTEX_ERROR -4

# define ERR_MSG_ARG "Arg Error: ./philo\n\
1 - <total_philos>\n\
2 - <time_to_die>\n\
3 - <time_to_eat>\n\
4 - <time_to_sleep>\n\
5 - <meals_needed>"

# define ERR_MSG_FORMAT "Format Error:\n\
1 - detected non-integer\n\
2 - philo exceed 200\n\
3 - detected negative values"

# define ERR_MSG_MALLOC "Malloc Error"

# define ERR_MSG_MUTEX "Mutex Error"

# define MAX_PHILO 200

typedef struct s_table	t_table;

typedef struct s_philo {
	pthread_t	thread;
	int	id;
	int	meals_ate;
	int	fork[2];
	time_t	last_meal;
	pthread_mutex_t	lock_last_meal;
	t_table	*table;
}	t_philo;

typedef struct s_table {
	time_t	timer;
	int	total_philos;
	int	die_at;
	int	eat_at;
	int	sleep_at;
	int	meals_needed;
	int	is_exit;
	pthread_t	monitor;
	pthread_mutex_t	lock_is_exit;
	pthread_mutex_t	lock_forks[MAX_PHILO];
	t_philo	philo[MAX_PHILO];
}	t_table;


// Error Handling

void	handle_error(t_table *table, int error_num);
void	cleanup(t_table *table);
void	destroy_mutexes(t_table *table);

// Utils libft

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);

// Parsing

int	parse_args(int ac, char **av);

// Initialize

void	initialize(t_table *table, int ac, char **av);
void	initialize_locks(t_table *table);
void	initialize_philo(t_table *table);
void	assign_forks(t_philo *philo, t_table *table);

// Utils philo

time_t	get_time_in_ms(void);

// Unit tests

void TEST_check_initialization(t_table *table);

#endif
