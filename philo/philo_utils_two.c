/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:06:26 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 17:18:00 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(int argc, char **argv)
{
	if (!ft_atoi(argv[1]) || !ft_atoi(argv[2]) || ft_atoi(argv[3])
		|| !ft_atoi(argv[4]))
		return (0);
	if (argc == 6)
		if (!ft_atoi(argv[5]))
			return (0);
	return (1);
}

static void	philo_init(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].philo_num = i;
		data->philos[i].action = THINK;
		data->philos[i].fork.left = true;
		data->philos[i++].fork.right = true;
	}
}

int	data_init(t_data *data, int ac, char **av)
{
	data->philo_count = ft_atoi(av[1]);
	data->philos = (t_philo *)malloc(data->philo_count * sizeof(t_philo));
	data->threads = (pthread_t *)malloc(data->philo_count * sizeof(pthread_t));
	if (!data->philos)
		return (0);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->food_count = ft_atoi(av[5]);
	philo_init(data);
	return (1);
}
