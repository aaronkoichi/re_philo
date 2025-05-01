/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:56:46 by zlee              #+#    #+#             */
/*   Updated: 2025/05/01 21:05:29 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *phi, enum e_action act)
{
	char	*string;

	if (act == THINK)
		string = "is thinking";
	else if (act == EAT)
		string = "is eating";
	else if (act == SLEEP)
		string = "is sleeping";
	else
		string = "has taken a fork";
	pthread_mutex_lock(phi->printf_lock);
	if (get_status(phi) == 0)
		printf("%d %d %s\n", get_ms_psd_gbl(phi), phi->philo_num, string);
	pthread_mutex_unlock(phi->printf_lock);
}
