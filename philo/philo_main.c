/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:53:24 by zlee              #+#    #+#             */
/*   Updated: 2025/05/02 16:25:45 by zlee             ###   ########.fr       */
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
		multi_thread_create(&data);
	else
		single_thread_create(&data);
	free_data(&data);
	return (0);
}
