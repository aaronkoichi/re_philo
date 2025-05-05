/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:01:12 by zlee              #+#    #+#             */
/*   Updated: 2025/05/05 21:58:21 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	free(data->all_forks);
	pthread_mutex_destroy(data->philos[0].printf_lock);
	free(data->philos[0].printf_lock);
	pthread_mutex_destroy(data->dead_lock);
	free(data->dead_lock);
	free(data->philos);
}
