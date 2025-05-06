/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:53:24 by zlee              #+#    #+#             */
/*   Updated: 2025/05/06 17:09:52 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc < 5 || argc > 6 || !check_args(argc, argv))
		return (0);
	if (!data_init(&data, argc, argv))
		return (0);
	set_all_forks(&data);
	if (data.philo_count > 1)
	{
		
		if (multi_thread_create(&data) != 0)
			printf("Error while creating threads\n");
	}
	else
	{
		if (single_thread_create(&data))
			printf("Error while creating threads\n");
	}
	free_data(&data);
	return (0);
}
