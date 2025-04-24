/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation_lonely_edition.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:23:03 by zlee              #+#    #+#             */
/*   Updated: 2025/04/24 21:45:38 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Let the philo takes a fork then immediately exits.
void	*lonely_simulation(void *args)
{
	t_philo	*phi;
	int		dead_check;

	phi = (t_philo *)args;
	dead_check = get_status(phi);
	set_philo_ms(phi, get_current_ms(phi->ms_lock));
	set_action(phi, THINK);
	pthread_mutex_lock(phi->fork.left);
	pthread_mutex_lock(phi->printf_lock);
	printf("%d %d has taken a fork\n", get_ms_passed_global(phi), phi->philo_num);
	pthread_mutex_unlock(phi->printf_lock);
	return (NULL);
}
