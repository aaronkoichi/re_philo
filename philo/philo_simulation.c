/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:04 by zlee              #+#    #+#             */
/*   Updated: 2025/04/09 16:39:36 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Monitor if the user died of starvation, or if all of them has completed
 * their number of meals.*/
void	*monitor(void *args)
{
	t_data	*data;
	
	data = (t_data *)args;
	return (NULL);
}

/*thinking state*/
static void	p_think(t_philo *phi, int *ms)
{
	int		p_ms;

	p_ms = 0;
	printf("%d %d is thinking\n", *ms, phi->philo_num);
	while (phi->term_count != 0 && phi->time_to_die < p_ms)
	{

		ft_usleep(1, ms);
	}
}

/*eating state*/
static void	p_eat(t_philo *phi, int *ms)
{

}

/*sleeping state*/
static void	p_sleep(t_philo *phi, int *ms)
{

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
		p_think(philo, &ms);
		p_eat(philo, &ms);
		p_sleep(philo, &ms);
	}
	return (NULL);
}

