/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/04/10 22:50:14 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*After they done sleeping, let them sleep again for a bit.
 * No Need to announce*/
static void p_doom_sleep(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		set_action(phi, THINK);
		set_action(phi, SLEEP);
		ft_usleep(10, &phi->p_ms);
	}
}

/*Order of them to pick up their fork.*/
static void	p_pickup_fork(t_philo *phi)
{
	if (!(phi->philo_num % 2))
	{
		pthread_mutex_lock(&phi->fork.left);
		printf("%d %d has taken a fork\n", get_ms(phi), phi->philo_num);
		pthread_mutex_lock(&phi->fork.right);
		printf("%d %d has taken a fork\n", get_ms(phi), phi->philo_num);
	}
	else
	{
		pthread_mutex_lock(&phi->fork.right);
		printf("%d %d has taken a fork\n", get_ms(phi), phi->philo_num);
		pthread_mutex_lock(&phi->fork.left);
		printf("%d %d has taken a fork\n", get_ms(phi), phi->philo_num);
	}
}

/*thinking and eating state*/
static void	p_think_eat(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		set_action(phi, THINK);
		printf("%d %d is thinking\n", get_ms(phi), phi->philo_num);
		p_pickup_fork(phi);
		set_action(phi, EAT);
		printf("%d %d is thinking\n", get_ms(phi), phi->philo_num);
		phi->p_ms = 0;
		printf("%d %d is eating\n", get_ms(phi), phi->philo_num);
		ft_usleep(phi->time_to_eat, &phi->p_ms);
		set_food_count(phi, get_food_count(phi));
		pthread_mutex_unlock(&phi->fork.left);
		pthread_mutex_unlock(&phi->fork.right);
	}
}

/*sleeping state*/
static void	p_sleep(t_philo *phi)
{
	int	dead_check;

	dead_check = get_status(phi);
	if (dead_check != 1)
	{
		set_action(phi, SLEEP);
		phi->p_ms = 0;
		printf("%d %d is sleeping\n", get_ms(phi), phi->philo_num);
		ft_usleep(phi->time_to_sleep, &phi->p_ms);
	}
}

/*THINK state --> think until a certain period
 * EAT state --> lock the fork. wait until a certain period
 * SLEEP state --> unlock the fork, wait until a certain period.*/
void	*simulation(void *args)
{
	t_philo		*philo;
	int			dead_check;

	dead_check = get_status(philo);
	philo = (t_philo *)args;
	while (dead_check != 1)
	{
		p_think_eat(philo);
		p_sleep(philo);
		p_doom_sleep(philo);
	}
	return (NULL);
}

