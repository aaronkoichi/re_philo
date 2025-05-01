/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/05/01 21:05:19 by zlee             ###   ########.fr       */
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
		pickup_left_fork(phi);
		pickup_right_fork(phi);
	}
	else
	{
		usleep(60);
		pickup_right_fork(phi);
		pickup_left_fork(phi);
	}
}

/*thinking and eating state*/
static void	p_think_eat(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		ft_print(phi, THINK);
		set_action(phi, THINK);
		p_pickup_fork(phi);
		if (get_status(phi) == 1)
			return ;
		set_action(phi, EAT);
		set_philo_ms(phi, get_current_ms(phi->ms_lock));
		if (get_status(phi) == 1)
			return ;
		ft_print(phi, EAT);
		usleep(phi->time_to_eat * 1000);
		set_food_count(phi);
	}
}

/*sleeping state*/
static void	p_sleep(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		pthread_mutex_unlock(phi->fork.left);
		pthread_mutex_unlock(phi->fork.right);
		set_action(phi, SLEEP);
		if (get_status(phi) == 1)
			return ;
		ft_print(phi, SLEEP);
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
	usleep(philo->philo_num);
	set_philo_ms(philo, get_current_ms(philo->ms_lock));
	while (dead_check != 1)
	{
		p_think_eat(philo);
		p_sleep(philo);
		p_doom_sleep(philo);
		dead_check = get_status(philo);
	}
	if (get_action(philo) == THINK || get_action(philo) == EAT)
	{
		pthread_mutex_unlock(philo->fork.left);
		pthread_mutex_unlock(philo->fork.right);
	}
	return (NULL);
}
