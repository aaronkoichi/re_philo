/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/04/10 15:48:58 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*After they done sleeping, let them sleep again for a bit.
 * No Need to announce*/
static void p_doom_sleep(t_philo *phi)
{
	if (*(phi->dead_int) != 1)
	{
		phi->action = THINK;
		phi->action = SLEEP;
		ft_usleep(10, &phi->p_ms);
	}
}

/*Order of them to pick up their fork.*/
static void	p_pickup_fork(t_philo *phi)
{
	if (!(phi->philo_num % 2))
	{
		pthread_mutex_lock(&phi->fork.left);
		printf("%d %d has taken a fork\n", *phi->g_ms, phi->philo_num);
		pthread_mutex_lock(&phi->fork.right);
		printf("%d %d has taken a fork\n", *phi->g_ms, phi->philo_num);
	}
	else
	{
		pthread_mutex_lock(&phi->fork.right);
		printf("%d %d has taken a fork\n", *phi->g_ms, phi->philo_num);
		pthread_mutex_lock(&phi->fork.left);
		printf("%d %d has taken a fork\n", *phi->g_ms, phi->philo_num);
	}
}

/*thinking and eating state*/
static void	p_think_eat(t_philo *phi)
{
	if (*(phi->dead_int) != 1)
	{
		phi->action = THINK;
		printf("%d %d is thinking\n", *phi->g_ms, phi->philo_num);
		p_pickup_fork(phi);
		phi->action = EAT;
		phi->p_ms = 0;
		printf("%d %d is eating\n", *phi->g_ms, phi->philo_num);
		ft_usleep(phi->time_to_eat, &phi->p_ms);
		phi->food_count++;
		pthread_mutex_unlock(&phi->fork.left);
		pthread_mutex_unlock(&phi->fork.right);
	}
	return ;
}

/*sleeping state*/
static void	p_sleep(t_philo *phi)
{
	if (*(phi->dead_int) != 1)
	{
		phi->action = SLEEP;
		phi->p_ms = 0;
		printf("%d %d is sleeping\n", *phi->g_ms, phi->philo_num);
		ft_usleep(phi->time_to_sleep, &phi->p_ms);
	}
}

/*THINK state --> think until a certain period
 * EAT state --> lock the fork. wait until a certain period
 * SLEEP state --> unlock the fork, wait until a certain period.*/
void	*simulation(void *args)
{
	t_philo		*philo;
	int			ms;

	ms = 0;
	philo = (t_philo *)args;
	printf("started\n");
	while (*(philo->dead_int) != 1)
	{
		p_think_eat(philo);
		p_sleep(philo);
		p_doom_sleep(philo);
	}
	return (NULL);
}

