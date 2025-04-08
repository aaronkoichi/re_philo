/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:27:18 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 16:47:00 by zlee             ###   ########.fr       */
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
	bool	left;
	bool	right;
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
}	t_philo;

/*Struct for Storing general data*/
typedef struct s_data
{
	t_philo			*philos;
	pthread_t		*threads;
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	food_count;
}	t_data;

/*Functions*/

/*parsing*/
/*philo_utils.c*/
unsigned int	ft_atoi(const char *nptr);
/*philo_utils_two.c*/
int				check_args(int argc, char **argv);
int				data_init(t_data *data, int ac, char **av);
#endif
