/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/04/09 17:36:14 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*thinking and eating state*/
static void	p_think_eat(t_philo *phi)
{
	phi->action = THINK;
	phi->p_ms = 0;
	printf("%d %d is thinking\n", *phi->g_ms, phi->philo_num);
	pthread_mutex_lock(&phi->fork.left);
	printf("%d %d has taken a fork\n", *phi->g_ms, phi->philo_num);
	pthread_mutex_lock(&phi->fork.right);
	printf("%d %d has taken a fork\n", *phi->g_ms, phi->philo_num);
	phi->action = EAT;
	phi->p_ms = 0;
	printf("%d %d is eating\n", *phi->g_ms, phi->philo_num);
	ft_usleep(phi->time_to_eat, &phi->p_ms);
	phi->food_count++;
	return ;
}

/*sleeping state*/
static void	p_sleep(t_philo *phi)
{
	phi->action = SLEEP;
	phi->p_ms = 0;
	printf("%d %d is sleeping\n", *phi->g_ms, phi->philo_num);
	ft_usleep(phi->time_to_sleep, &phi->p_ms);
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
	while (*(philo->term_count) != 1)
	{
		p_think_eat(philo);
		p_sleep(philo);
	}
	return (NULL);
}

