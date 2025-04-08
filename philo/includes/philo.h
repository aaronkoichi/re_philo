/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:27:18 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 15:21:41 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*Struct for fork*/
typedef struct s_fork
{
	bool	left;
	bool	right;
}	t_fork;

/* Struct for storing philo data. */
typedef struct s_philo
{
	unsigned int	philo_num;
	t_fork			fork;
}	t_philo;

/*Struct for Storing general data*/
typedef struct s_data
{
	t_philo			*philos;
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
int 			check_args(int argc, char **argv);
int				data_init(t_data *data, int ac, char **av);
#endif
