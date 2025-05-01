/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_getter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:25:39 by zlee              #+#    #+#             */
/*   Updated: 2025/05/01 16:00:18 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_status(t_philo *philo)
{
	int	status;

	usleep(10);
	status = 0;
	pthread_mutex_lock(philo->dead_lock);
	status = *philo->dead_int;
	pthread_mutex_unlock(philo->dead_lock);
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

	status = 0;
	usleep(10);
	pthread_mutex_lock(data->dead_lock);
	status = data->dead_int;
	pthread_mutex_unlock(data->dead_lock);
	return (status);
}
