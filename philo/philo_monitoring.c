/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:57:15 by zlee              #+#    #+#             */
/*   Updated: 2025/04/21 17:27:19 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Check if any philo has go over their state, and also increament
 * the counter for each philo.*/
static void	check_state(t_philo *philo)
{
	if (get_status(philo) == THINK)
		if (get_ms_passed_philo(*philo) >= philo->time_to_die)
		{
			pthread_mutex_lock(philo->printf_lock);
			printf("%d %d died\n", get_ms_passed_global(philo),
		  		philo->philo_num);
			pthread_mutex_unlock(philo->printf_lock);
			set_status(philo, 1);
		}
}

static int	check_meals(t_data *data)
{
	unsigned int	phi;

	phi = 0;
	while (phi < data->philo_count)
		if (get_food_count(&data->philos[phi++]) < data->total_food)
			return (0);
	return (1);
}

/*Monitor if the user died of starvation, or if all of them has completed
 * their number of meals.*/
void	*monitor(void *args)
{
	t_data				*data;
	unsigned int		count;
	int					status;
	
	data = (t_data *)args;
	status = get_data_status(data);
	// while (status != 1)
	// {
	// 	count = 0;
	// 	while (count < data->philo_count)
	// 		check_state(&data->philos[count++]);
	// 	if (data->meals == true)
	// 		if (check_meals(data))
	// 			set_data_status(data, 1);
	// 	status = get_data_status(data);
	// }
	return (NULL);
}

