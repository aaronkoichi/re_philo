/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:13:25 by zlee              #+#    #+#             */
/*   Updated: 2025/04/17 20:29:32 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_all_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->all_forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	while (i < data->philo_count - 1)
	{
		pthread_mutex_init(&data->all_forks[i], NULL);
		data->philos[i].fork.right = &data->all_forks[i];
		data->philos[i + 1].fork.left = &data->all_forks[i];
		i++;
	}
		pthread_mutex_init(&data->all_forks[i], NULL);
		data->philos[i].fork.right = &data->all_forks[i];
		data->philos[0].fork.left = &data->all_forks[i];
}
