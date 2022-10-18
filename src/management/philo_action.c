/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:14:07 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 17:05:58 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->left_fork]));
	philo_talk(data, philo, "has taken a fork");
	pthread_mutex_lock(&(data->fork[philo->right_fork]));
	philo_talk(data, philo, "has taken a fork");
	philo_talk(data, philo, "is eating");
	pthread_mutex_lock(&(data->meal));
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&(data->meal));
	wait_action(data->eat_time);
	pthread_mutex_lock(&(data->meal));
	(philo->did_eat)++;
	pthread_mutex_unlock(&(data->meal));
	pthread_mutex_unlock(&(data->fork[philo->left_fork]));
	pthread_mutex_unlock(&(data->fork[philo->right_fork]));
}

void	routine_extend(t_philo *philo, t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->is_dead);
		if (data->dead)
		{
			pthread_mutex_unlock(&data->is_dead);
			break ;
		}
		pthread_mutex_unlock(&data->is_dead);
		eat(philo);
		pthread_mutex_lock(&data->meal);
		if (data->all_ate)
		{
			pthread_mutex_unlock(&data->meal);
			break ;
		}
		pthread_mutex_unlock(&data->meal);
		philo_talk(data, philo, "is sleeping");
		wait_action(data->sleep_time);
		philo_talk(data, philo, "is thinking");
		usleep(1000);
	}
}

void	*routine(void *args)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2)
		usleep((philo->data->eat_time / 2) * 1000);
	routine_extend(philo, data);
	return (NULL);
}

void	philo_pthread(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	data->time_stamp = timestamp();
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].philo_pth, NULL, &routine, &philo[i]))
			exit(EXIT_FAILURE);
		pthread_mutex_lock(&data->meal);
		philo[i].last_meal = timestamp();
		pthread_mutex_unlock(&data->meal);
		i++;
	}
	check_alive(data, philo);
	exit_phtread(data, philo);
}
