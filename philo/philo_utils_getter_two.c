/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_getter_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:46:25 by zlee              #+#    #+#             */
/*   Updated: 2025/04/10 22:48:22 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_action	get_action(t_philo *philo)
{
	enum e_action	action;

	pthread_mutex_lock(&philo->action.lock);
	action = philo->action.action;
	pthread_mutex_unlock(&philo->action.lock);
	return (action);
}
