/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:08:20 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 15:14:30 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philo[i].id = i + 1;
		data->philo[i].did_eat = 0;
		data->philo[i].last_meal = 0;
		if (i % 2)
		{
			data->philo[i].left_fork = (i + 1) % data->nb_philo;
			data->philo[i].right_fork = i;
		}
		else
		{
			data->philo[i].right_fork = (i + 1) % data->nb_philo;
			data->philo[i].left_fork = i;
		}
		data->philo[i].data = data;
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&data->fork[i + 1], NULL))
			exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&data->meal, NULL))
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&data->write, NULL))
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&data->is_dead, NULL))
		exit(EXIT_FAILURE);
}

void	init_all(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->all_ate = false;
	data->nb_of_eat = -1;
	data->dead = false;
	if (av[5] != NULL && ft_atoi(av[5]) > 0)
		data->nb_of_eat = ft_atoi(av[5]);
	init_philo(data);
	init_mutex(data);
}
