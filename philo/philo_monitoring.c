/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:57:15 by zlee              #+#    #+#             */
/*   Updated: 2025/04/10 15:33:04 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Check if any philo has go over their state, and also increament
 * the counter for each philo.*/
static void	check_state(t_philo *philo)
{
	if (philo->action == THINK)
		if (philo->p_ms >= philo->time_to_die)
		{
			printf("%d %d died\n", *philo->g_ms, philo->philo_num);
			*(philo->dead_int) = 1;
		}
}

static int	check_meals(t_data *data)
{
	unsigned int	phi;

	phi = 0;
	while (phi < data->philo_count)
		if (data->philos[phi++].food_count < data->food_count)
			return (0);
	return (1);
}

/*Monitor if the user died of starvation, or if all of them has completed
 * their number of meals.*/
void	*monitor(void *args)
{
	t_data				*data;
	unsigned int		count;
	
	data = (t_data *)args;
	while (data->dead_int != 1)
	{
		count = 0;
		while (count < data->philo_count)
			check_state(&data->philos[count++]);
		if (data->meals == true)
			if (check_meals(data))
				data->dead_int= 1;
		ft_usleep(1, args);
	}
	return (NULL);
}

