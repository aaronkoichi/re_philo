/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:13:25 by zlee              #+#    #+#             */
/*   Updated: 2025/04/16 21:52:39 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_all_forks(t_data *data)
{
	unsigned int	i;
	pthread_mutex_t	*thread;

	i = 0;
	thread = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	while (i < data->philo_count - 1)
	{
		pthread_mutex_init(&thread[i], NULL);
		data->philos[i].fork.right = &thread[i];
		data->philos[i + 1].fork.left = &thread[i];
		printf("address 1: %p\n", data->philos[i].fork.right);
		printf("address 2: %p\n", data->philos[i + 1].fork.left);
		i++;
	}
		pthread_mutex_init(&thread[i], NULL);
		data->philos[i].fork.right = &thread[i];
		data->philos[0].fork.left = &thread[i];

}
