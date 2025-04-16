/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:06:26 by zlee              #+#    #+#             */
/*   Updated: 2025/04/16 14:56:55 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int check_args(int argc, char **argv)
{
	if (ft_atoi(argv[1]) && ft_atoi(argv[2]) && ft_atoi(argv[3])
		&& ft_atoi(argv[4]))
	{
		if (argc == 6)
		{
			if (ft_atoi(argv[5]))
				return (1);
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

static void	philo_init(t_data *data, char **av)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].philo_num = i;
		data->philos[i].status = &(data->status);
		set_action(&data->philos[i], THINK);
		data->philos[i].time_to_die = ft_atoi(av[2]);
		data->philos[i].time_to_eat = ft_atoi(av[3]);
		data->philos[i].time_to_sleep = ft_atoi(av[4]);
		data->philos[i].food_count.count = 0;
		data->philos[i].g_ms = &data->ms;
		pthread_mutex_init(&data->philos[i].food_count.lock, NULL);
		i++;
	}
}

int	data_init(t_data *data, int ac, char **av)
{
	data->philo_count = ft_atoi(av[1]);
	data->ms.ms = get_current_ms();
	pthread_mutex_init(&data->ms.lock, NULL);
	data->status.dead_int = 0;
	pthread_mutex_init(&data->status.lock, NULL);
	data->philos = (t_philo *)malloc(data->philo_count * sizeof(t_philo));
	if (!data->philos)
		return (0);
	philo_init(data, av);
	if (ac == 6)
	{
		data->total_food = ft_atoi(av[5]);
		data->meals = true;
	}
	else
		data->meals = false;
	return (1);
}
