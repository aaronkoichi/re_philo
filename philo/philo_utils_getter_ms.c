/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_getter_ms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:29:35 by zlee              #+#    #+#             */
/*   Updated: 2025/05/01 16:00:28 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_ms_passed_philo(t_philo phi)
{
	unsigned int	current_ms;
	unsigned int	philo_ms;

	current_ms = get_current_ms(phi.ms_lock);
	philo_ms = get_philo_ms(&phi);
	if (philo_ms == 0)
		return (0);
	else
		return (current_ms - philo_ms);
}

unsigned int	get_ms_psd_gbl(t_philo *philo)
{
	return (get_current_ms(philo->ms_lock) - get_global_ms(philo));
}

unsigned int	get_philo_ms(t_philo *philo)
{
	unsigned int	ms;

	pthread_mutex_lock(&philo->p_ms.lock);
	ms = philo->p_ms.ms;
	pthread_mutex_unlock(&philo->p_ms.lock);
	return (ms);
}

unsigned int	get_global_ms(t_philo *philo)
{
	unsigned int	ms;

	pthread_mutex_lock(&philo->g_ms->lock);
	ms = philo->g_ms->ms;
	pthread_mutex_unlock(&philo->g_ms->lock);
	return (ms);
}

unsigned int	get_current_ms(pthread_mutex_t	*lock)
{
	struct timeval	tv;
	unsigned int	current;

	current = 0;
	pthread_mutex_lock(lock);
	gettimeofday(&tv, NULL);
	current = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	pthread_mutex_unlock(lock);
	return (current);
}
