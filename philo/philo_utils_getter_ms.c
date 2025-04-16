/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_getter_ms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:29:35 by zlee              #+#    #+#             */
/*   Updated: 2025/04/16 15:38:36 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_ms_passed_philo(t_philo phi)
{
	unsigned int	ms;

	ms = get_current_ms() - get_philo_ms(&phi);
	return (ms);
}

unsigned int	get_ms_passed_global(t_philo *philo)
{
	return (get_current_ms() - get_global_ms(philo));
}
