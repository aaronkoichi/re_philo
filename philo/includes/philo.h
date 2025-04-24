/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:27:18 by zlee              #+#    #+#             */
/*   Updated: 2025/04/24 17:10:12 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdint.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

/*Struct for fork*/
typedef struct s_fork
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_fork;

/*Enum for actions*/
enum e_action{
	THINK,
	EAT,
	SLEEP
};

/*Struct for ready status
 * --> To check if all threads are ready (so to start the
 *  action concurrently.)*/
typedef struct s_ready
{
	bool			status;
	pthread_mutex_t	lock;
}	t_ready;

/*Struct for food*/
typedef struct	s_food
{
	unsigned int	count;
	pthread_mutex_t	lock;
}	t_food;

/*Struct to mark the status of dead*/
// typedef struct s_dead
// {
// 	int				dead_int;
// 	pthread_mutex_t	lock;
// }	t_dead;

/*Struct to mark the miliseconds that has passed.*/
typedef struct s_ms
{
	long			ms;
	pthread_mutex_t	lock;
}	t_ms;

typedef struct s_action
{
	enum e_action	action;
	pthread_mutex_t	lock;
}	t_action;

/* Struct for storing philo data. */
typedef struct s_philo
{
	unsigned int	philo_num;
	pthread_t		thread;
	t_fork			fork;
	t_action		action;
	pthread_mutex_t	*ms_lock;
	pthread_mutex_t	*printf_lock;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	t_food			food_count;
	int				*dead_int;
	pthread_mutex_t	*dead_lock;
	t_ms			p_ms;
	t_ms			*g_ms;
}	t_philo;

/*Struct for Storing general data*/
typedef struct s_data
{
	bool			meals;
	t_philo			*philos;
	pthread_mutex_t	*all_forks;
	pthread_t		monitor_thread;
	pthread_mutex_t	ms_lock;
	int				dead_int;
	pthread_mutex_t	*dead_lock;
	unsigned int	philo_count;
	unsigned int	total_food;
	t_ms			ms;
}	t_data;

/*Functions*/
/*parsing*/
/*philo_utils.c*/
unsigned int	ft_atoi(const char *nptr);
void			ft_usleep(unsigned int sleep, unsigned int *ms);
unsigned int	get_current_ms(pthread_mutex_t	*lock);
/*philo_utils_two.c*/
int				check_args(int argc, char **argv);
int				data_init(t_data *data, int ac, char **av);
/*philo_set_forks.c*/
void			set_all_forks(t_data *data);
/*philo_simulation.c*/
void			*simulation(void *args);
void			*monitor(void *args);
/*philo_threads.c*/
int				create_thread(t_data *data);
/*philo_utils_getter.c*/
int				get_status(t_philo *philo);
unsigned int	get_food_count(t_philo *philo);
int				get_data_status(t_data *data);
/*philo_utils_getter_two.c*/
enum e_action	get_action(t_philo *philo);
/*philo_utils_setter.c*/
void			set_philo_ms(t_philo *philo, unsigned int ms);
void			set_status(t_philo *philo, int num);
void			set_food_count(t_philo *philo, int num);
void			set_data_status(t_data *data, int num);
void			set_action(t_philo *philo, enum e_action act);
/*philo_utils_getter_ms.c*/
unsigned int	get_global_ms(t_philo *philo);
unsigned int	get_philo_ms(t_philo *philo);
unsigned int	get_ms_passed_global(t_philo *philo);
unsigned int	get_ms_passed_philo(t_philo phi);
#endif
