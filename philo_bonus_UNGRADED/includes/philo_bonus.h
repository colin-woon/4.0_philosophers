/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:44:29 by cwoon             #+#    #+#             */
/*   Updated: 2025/02/24 17:36:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define ARG_ERROR -1
# define FORMAT_ERROR -2
# define MALLOC_ERROR -3
# define MUTEX_ERROR -4
# define THREAD_ERROR -5

# define PRINT_SEM "/semaphore_print"
# define IS_DEAD_SEM "/semaphore_is_dead"
# define IS_EXIT_SEM "/semaphore_is_exit"
# define GLOBAL_SEM "/semaphore_global"
# define EAT_ROUTINE_SEM "/semaphore_eat_routine"
# define FORKS_SEM "/semaphore_forks"

# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define COLOUR "\033[0m"

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}	t_status;

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
# define ERR_MSG_THREAD "Thread Error"

# define MAX_PHILO 200

typedef struct s_table	t_table;

typedef struct s_philo
{
	int			id;
	int			meals_required;
	time_t		last_meal;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	time_t		timer;
	int			total_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_needed;
	int			is_exit;
	int			has_dead_philo;
	pid_t		pid[MAX_PHILO];
	sem_t		*sem_print;
	sem_t		*sem_is_exit;
	sem_t		*sem_is_dead;
	sem_t		*sem_global;
	sem_t		*sem_eat_routine;
	sem_t		*sem_forks;
	t_philo		philo[MAX_PHILO];
}	t_table;

// Error Handling

void	handle_error(t_table *table, int error_num);
void	cleanup(t_table *table);

// Utils semaphore

void	my_sem_remove(sem_t *sem, char *sem_file);
void	cleanup_semaphores(t_table *table);

// Utils libft

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);

// Parsing

int		parse_args(char **av);

// Initialize

void	initialize(t_table *table, int ac, char **av);
void	initialize_semaphores(t_table *table);
void	initialize_philo(t_table *table);
void	assign_forks(t_philo *philo, t_table *table);

// Routine

void	routine(t_philo *philo);
void	lonely_philo(t_philo *philo);

// Utils philo

time_t	get_time_in_ms(void);
void	waiting(t_table *table, time_t waiting_time);
int		is_exit_simulation(t_table *table);
int		is_dead(t_philo *philo);

// Print

void	print_action(t_philo *philo, t_status status);
void	print_status(t_philo *philo, char *str, t_status status);

#endif
