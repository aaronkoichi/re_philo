/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:27:18 by zlee              #+#    #+#             */
/*   Updated: 2025/04/09 16:34:35 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

/*Struct for fork*/
typedef struct s_fork
{
	pthread_mutex_t	left;
	pthread_mutex_t	right;
}	t_fork;

/*Enum for actions*/
enum e_action{
	THINK,
	EAT,
	SLEEP
};

/* Struct for storing philo data. */
typedef struct s_philo
{
	unsigned int	philo_num;
	t_fork			fork;
	enum e_action	action;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	food_count;
	int				*term_count;
}	t_philo;

/*Struct for Storing general data*/
typedef struct s_data
{
	bool			meals;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_t		monitor_thread;
	int				*dead_int;
	unsigned int	philo_count;
	unsigned int	food_count;
}	t_data;

/*Functions*/
/*parsing*/
/*philo_utils.c*/
unsigned int	ft_atoi(const char *nptr);
void			ft_usleep(unsigned int sleep, int *ms);
/*philo_utils_two.c*/
int				check_args(int argc, char **argv);
int				data_init(t_data *data, int ac, char **av);
/*philo_set_forks.c*/
void			set_all_forks(t_data *data);
/*philo_simulation.c*/
void			*simulation(void *args);
#endif
