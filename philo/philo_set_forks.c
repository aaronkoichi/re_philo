/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philio_set_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:13:25 by zlee              #+#    #+#             */
/*   Updated: 2025/04/09 15:03:00 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks(pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	int				err;
	pthread_mutex_t	temp;

	err = pthread_mutex_init(&temp, NULL);
	if (err != 0)
		return ;
	f1 = &temp;
	f2 = &temp;
}

void	set_all_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_count - 1)
	{
		set_forks(&data->philos[i].fork.right, &data->philos[i + 1].fork.left);
		i++;
	}
	set_forks(&data->philos[i + 1].fork.right, &data->philos[0].fork.left);
}
