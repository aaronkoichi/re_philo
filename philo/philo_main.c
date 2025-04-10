/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:53:24 by zlee              #+#    #+#             */
/*   Updated: 2025/04/10 15:49:30 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (argc < 5 || argc > 6 || !check_args(argc, argv))
	{
		printf("lol\nargs:%d\n", argc);
		return (0);
	}
	if (!data_init(&data, argc, argv))
		return (0);
	printf("here\n");
	set_all_forks(&data);
	create_thread(&data);
	free(data.philos);
	return (0);
}
