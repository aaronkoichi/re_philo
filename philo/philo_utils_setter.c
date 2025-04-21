/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_setter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:51:00 by zlee              #+#    #+#             */
/*   Updated: 2025/04/21 17:13:39 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	set_status(t_philo *philo, int num)
{
	pthread_mutex_lock(philo->dead_lock);
	*philo->dead_int = num;
	pthread_mutex_unlock(philo->dead_lock);
}

void	set_food_count(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo->food_count.lock);
	philo->food_count.count = num;
	pthread_mutex_unlock(&philo->food_count.lock);
}

void	set_data_status(t_data *data, int num)
{
	pthread_mutex_lock(data->dead_lock);
	data->dead_int = num;
	pthread_mutex_unlock(data->dead_lock);
}

void	set_action(t_philo *philo, enum e_action act)
{
	pthread_mutex_lock(&philo->action.lock);
	philo->action.action = act;
	pthread_mutex_unlock(&philo->action.lock);
}

void	set_philo_ms(t_philo *philo, unsigned int ms)
{
	pthread_mutex_lock(&philo->p_ms.lock);
	philo->p_ms.ms = ms;
	pthread_mutex_unlock(&philo->p_ms.lock);
}
