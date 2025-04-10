/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:06:26 by zlee              #+#    #+#             */
/*   Updated: 2025/04/10 15:52:39 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		data->philos[i].dead_int = &(data->dead_int);
		data->philos[i].action = THINK;
		data->philos[i].time_to_die = ft_atoi(av[2]);
		data->philos[i].time_to_eat = ft_atoi(av[3]);
		data->philos[i].time_to_sleep = ft_atoi(av[4]);
		data->philos[i].p_ms = 0;
		data->philos[i].food_count = 0;
		data->philos[i].g_ms = &data->ms;
		i++;
	}
}

int	data_init(t_data *data, int ac, char **av)
{
	data->philo_count = ft_atoi(av[1]);
	data->dead_int = 0;
	data->ms = 0;
	data->philos = (t_philo *)malloc(data->philo_count * sizeof(t_philo));
	if (!data->philos)
		return (0);
	data->threads = (pthread_t *)malloc(data->philo_count * sizeof(pthread_t));
	philo_init(data, av);
	if (ac == 6)
	{
		data->food_count = ft_atoi(av[5]);
		data->meals = true;
	}
	else
		data->meals = false;
	return (1);
}
