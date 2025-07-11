/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:06:26 by zlee              #+#    #+#             */
/*   Updated: 2025/07/11 19:03:55 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_dead(t_data *data)
{
	pthread_mutex_t	*temp;
	unsigned int	i;

	i = 0;
	temp = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(temp, NULL);
	data->dead_lock = temp;
	while (i < data->philo_count)
	{
		data->philos[i].dead_lock = data->dead_lock;
		data->philos[i].dead_int = &(data->dead_int);
		i++;
	}
}

int	check_args(int argc, char **argv)
{
	if (valid_checker(argv[1]) && ft_atoi(argv[1]) && valid_checker(argv[2])
		&& valid_checker(argv[3]) && valid_checker(argv[4]))
	{
		if (argc == 6)
		{
			if (valid_checker(argv[5]))
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
	pthread_mutex_t	*temp;

	i = 0;
	temp = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&temp[0], NULL);
	while (i < data->philo_count)
	{
		memset(&data->philos[i], 0, sizeof(t_philo));
		data->philos[i].philo_num = i + 1;
		pthread_mutex_init(&data->philos[i].action.lock, NULL);
		pthread_mutex_init(&data->philos[i].p_ms.lock, NULL);
		set_action(&data->philos[i], THINK);
		data->philos[i].time_to_die = ft_atoi(av[2]);
		data->philos[i].time_to_eat = ft_atoi(av[3]);
		data->philos[i].time_to_sleep = ft_atoi(av[4]);
		data->philos[i].g_ms = &data->ms;
		data->philos[i].ms_lock = &data->ms.lock;
		data->philos[i].printf_lock = temp;
		pthread_mutex_init(&data->philos[i].food_count.lock, NULL);
		i++;
	}
}

int	data_init(t_data *data, int ac, char **av)
{
	data->philo_count = ft_atoi(av[1]);
	pthread_mutex_init(&data->ms.lock, NULL);
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
	init_dead(data);
	return (1);
}
