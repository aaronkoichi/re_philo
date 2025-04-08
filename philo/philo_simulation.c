/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 16:58:12 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation(void *args)
{
	
	return (NULL);
}

/*Creates the thread, parse it onto the above function.*/
void	create_thread(t_data *data)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (i < data->philo_count)
	{
		checker = pthread_create(&data->threads[i++], NULL, simulation, data);
		if (checker != 0)
			return ;
	}
	while(--i >= 0)
		pthread_join(data->threads[i], NULL);
}
