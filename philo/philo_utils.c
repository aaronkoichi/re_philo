/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:59:10 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 14:05:27 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
