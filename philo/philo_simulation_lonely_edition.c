/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation_lonely_edition.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:23:03 by zlee              #+#    #+#             */
/*   Updated: 2025/05/07 00:12:04 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Let the philo takes a fork then immediately exits.
void	*lonely_simulation(void *args)
{
	t_philo	*phi;

	phi = (t_philo *)args;
	set_philo_ms(phi, get_current_ms(phi->ms_lock));
	set_action(phi, THINK);
	pthread_mutex_lock(phi->fork.left);
	pthread_mutex_lock(phi->printf_lock);
	printf("%d %d has taken a fork\n", get_ms_psd_gbl(phi), phi->philo_num);
	pthread_mutex_unlock(phi->printf_lock);
	pthread_mutex_unlock(phi->fork.left);
	return (NULL);
}
