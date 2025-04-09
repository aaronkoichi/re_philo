/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:20:19 by zlee              #+#    #+#             */
/*   Updated: 2025/04/09 16:20:58 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Creates the thread, parse it onto the above function.
 * Not a convention way, but returning -1 to make sure everything is ok
 * Other than that it s*/
int	create_thread(t_data *data)
{
	unsigned int	i;
	int				checker;

	i = 0;
	checker = 0;
	while (i < data->philo_count)
	{
		checker = pthread_create(&data->threads[i], NULL, 
				simulation, &(data->philos[i]));
		if (checker != 0)
			return ((unsigned int)i);
		i++;
	}
	while(--i >= 0)
		pthread_join(data->threads[i], NULL);
	return (-1);
}


