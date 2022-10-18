/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:20 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 15:20:00 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_talk(t_data *data, t_philo *philo, char *message)
{
	pthread_mutex_lock(&data->write);
	pthread_mutex_lock(&data->is_dead);
	if (!data->dead)
	{
		pthread_mutex_unlock(&data->is_dead);
		printf("%lli %d %s\n", timestamp() - data->time_stamp, \
		philo->id, message);
	}
	else
		pthread_mutex_unlock(&data->is_dead);
	pthread_mutex_unlock(&data->write);
	return ;
}
