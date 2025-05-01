/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation_pickup_forks.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:13:51 by zlee              #+#    #+#             */
/*   Updated: 2025/05/01 21:03:11 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup_left_fork(t_philo *phi)
{
	pthread_mutex_lock(phi->fork.left);
	if (get_status(phi) == 1)
		return ;
	ft_print(phi, TAKE);
}

void	pickup_right_fork(t_philo *phi)
{
	pthread_mutex_lock(phi->fork.right);
	if (get_status(phi) == 1)
		return ;
	ft_print(phi, TAKE);
}
