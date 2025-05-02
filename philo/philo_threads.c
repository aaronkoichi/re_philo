/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:20:19 by zlee              #+#    #+#             */
/*   Updated: 2025/05/02 15:18:47 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	single_thread_create(t_data *data)
{
	int	checker;

	checker = 0;
	checker = pthread_create(&data->philos[0].thread, NULL,
			lonely_simulation, &(data->philos[0]));
	if (checker != 0)
		return (1);
	pthread_create(&data->monitor_thread, NULL, monitor, data);
	pthread_join(data->monitor_thread, NULL);
	pthread_join(data->philos[0].thread, NULL);
	return (0);
}

int	multi_thread_create(t_data *data)
{
	unsigned int	i;
	int				checker;

	i = 0;
	checker = 0;
	data->ms.ms = get_current_ms(&data->ms_lock);
	while (i < data->philo_count)
	{
		checker = pthread_create(&data->philos[i].thread, NULL,
				simulation, &(data->philos[i]));
		if (checker != 0)
			return ((unsigned int)i);
		i++;
	}
	pthread_create(&data->monitor_thread, NULL, monitor, data);
	i = -1;
	pthread_join(data->monitor_thread, NULL);
	while (++i < data->philo_count)
		pthread_join(data->philos[i].thread, NULL);
	return (0);
}
