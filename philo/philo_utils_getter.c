/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_getter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:25:39 by zlee              #+#    #+#             */
/*   Updated: 2025/04/16 16:27:31 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_status(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->status->lock);
	status = philo->status->dead_int;
	pthread_mutex_unlock(&philo->status->lock);
	return (status);
}

unsigned int	get_food_count(t_philo *philo)
{
	int	count;
	
	pthread_mutex_lock(&philo->food_count.lock);
	count = philo->food_count.count;
	pthread_mutex_unlock(&philo->food_count.lock);
	return (count);
}

int	get_data_status(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->status.lock);
	status = data->status.dead_int;
	pthread_mutex_unlock(&data->status.lock);
	return (status);
}

