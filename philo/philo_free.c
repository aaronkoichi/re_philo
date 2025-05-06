/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:01:12 by zlee              #+#    #+#             */
/*   Updated: 2025/05/07 00:47:53 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	count;

	count = -1;
	while (++count < data->philo_count)
	{
		pthread_mutex_destroy(&data->all_forks[count]);
		pthread_mutex_destroy(&data->philos[count].p_ms.lock);
		pthread_mutex_destroy(&data->philos[count].action.lock);
		pthread_mutex_destroy(&data->philos[count].food_count.lock);
	}
	free(data->all_forks);
	pthread_mutex_destroy(&data->ms.lock);
	pthread_mutex_destroy(data->philos[0].printf_lock);
	free(data->philos[0].printf_lock);
	pthread_mutex_destroy(data->dead_lock);
	free(data->dead_lock);
	free(data->philos);
}
