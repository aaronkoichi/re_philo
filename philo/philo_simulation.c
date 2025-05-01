/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/05/01 16:16:07 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*After they done sleeping, let them sleep again for a bit.
 * No Need to announce*/
static void	p_doom_sleep(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		set_action(phi, THINK);
		set_action(phi, SLEEP);
		usleep(60);
	}
}

/*Order of them to pick up their fork.*/
static void	p_pickup_fork(t_philo *phi)
{
	if (!(phi->philo_num % 2))
	{
		pthread_mutex_lock(phi->fork.left);
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d has taken a fork\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
		pthread_mutex_lock(phi->fork.right);
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d has taken a fork\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
	}
	else
	{
		pthread_mutex_lock(phi->fork.right);
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d has taken a fork\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
		pthread_mutex_lock(phi->fork.left);
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d has taken a fork\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
	}
}

/*thinking and eating state*/
static void	p_think_eat(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d is thinking\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
		set_action(phi, THINK);
		p_pickup_fork(phi);
		set_action(phi, EAT);
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d is eating\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
		usleep(phi->time_to_eat * 1000);
		set_food_count(phi);
		set_philo_ms(phi, get_current_ms(phi->ms_lock));
	}
}

/*sleeping state*/
static void	p_sleep(t_philo *phi)
{
	int	dead_check;

	pthread_mutex_unlock(phi->fork.left);
	pthread_mutex_unlock(phi->fork.right);
	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		set_action(phi, SLEEP);
		pthread_mutex_lock(phi->printf_lock);
		printf("%d %d is sleeping\n", get_ms_psd_gbl(phi), phi->philo_num);
		pthread_mutex_unlock(phi->printf_lock);
		usleep(phi->time_to_sleep * 1000);
	}
}

/*THINK state --> think until a certain period
 * EAT state --> lock the fork. wait until a certain period
 * SLEEP state --> unlock the fork, wait until a certain period.*/
void	*simulation(void *args)
{
	t_philo		*philo;
	int			dead_check;

	philo = (t_philo *)args;
	dead_check = get_status(philo);
	set_philo_ms(philo, get_current_ms(philo->ms_lock));
	while (dead_check != 1)
	{
		p_think_eat(philo);
		p_sleep(philo);
		p_doom_sleep(philo);
		dead_check = get_status(philo);
	}
	return (NULL);
}
