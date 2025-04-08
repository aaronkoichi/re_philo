/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 17:36:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation(void *args)
{
	t_data	*data;

	data = (t_data *)args;
	pthread_mutex_lock(&data->mutex);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

/*Creates the thread, parse it onto the above function.
 * Not a convention way, but returning -1 to make sure everything is ok
 * Other than that it s*/

int	create_thread(t_data *data)
{
	unsigned int	i;
	int				checker;

	i = 0;
	checker = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->philo_count)
	{
		checker = pthread_create(&data->threads[i++], NULL, simulation, data);
		if (checker != 0)
			return ((unsigned int)i);
	}
	while(--i >= 0)
		pthread_join(data->threads[i], NULL);
	return (-1);
}
