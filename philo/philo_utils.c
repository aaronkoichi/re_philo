/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:59:10 by zlee              #+#    #+#             */
/*   Updated: 2025/04/16 15:06:17 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>

static unsigned int	count_ws(const char *nptr)
{
	int	index;

	index = 0;
	while (nptr[index] == 32 || (nptr[index] >= 9 && nptr[index] <= 13))
		index++;
	return (index);
}

unsigned int	ft_atoi(const char *nptr)
{
	int	multiple;
	int	index;
	int	total;

	multiple = 1;
	total = 0;
	index = count_ws(nptr);
	if (nptr[index] == '+')
		index++;
	while (nptr[index] >= '0' && nptr[index] <= '9')
		total = (total * 10) + (nptr[index++] - 48);
	return (total * multiple);
}

void	ft_usleep(unsigned int sleep, unsigned int *ms)
{
	unsigned int 	i;
	i = 0;

	while (i < sleep)
	{
		usleep(1);
		(*ms)++;
		i++;
	}
}

unsigned int	get_current_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
