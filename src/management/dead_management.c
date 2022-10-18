/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:52:15 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 15:12:49 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exit_phtread(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(philo[i].philo_pth, NULL))
			exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->is_dead);
}

void	check_alive_extend(t_data *data, t_philo *philo, int i)
{
	while (++i < data->nb_philo && !(data->dead))
	{
		pthread_mutex_lock(&data->meal);
		if (timediff(philo[i].last_meal, timestamp()) > data->die_time)
		{
			pthread_mutex_unlock(&data->meal);
			philo_talk(data, philo, "died");
			pthread_mutex_lock(&data->is_dead);
			data->dead = true;
			pthread_mutex_unlock(&data->is_dead);
		}
		else
			pthread_mutex_unlock(&data->meal);
		usleep(150);
	}
	pthread_mutex_lock(&data->meal);
}

void	check_alive(t_data *data, t_philo *philo)
{
	int	i;

	while (!(data->all_ate))
	{
		i = -1;
		check_alive_extend(data, philo, i);
		if (data->dead)
		{
			pthread_mutex_unlock(&data->meal);
			break ;
		}
		pthread_mutex_unlock(&data->meal);
		i = 0;
		while (data->nb_of_eat != -1 && i < data->nb_philo
			&& philo[i].did_eat >= data->nb_of_eat)
			i++;
		pthread_mutex_lock(&data->meal);
		if (i == data->nb_philo)
		{
			data->all_ate = true;
			pthread_mutex_unlock(&data->meal);
		}
		else
			pthread_mutex_unlock(&data->meal);
	}
}
