/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:05:41 by gkitoko           #+#    #+#             */
/*   Updated: 2022/07/25 15:17:25 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	timediff(long long start, long long end)
{
	return (end - start);
}

long long    timestamp(void)
{
    struct timeval    t;

    gettimeofday(&t, NULL);
    return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	*routine(void *arg)
{	
	t_data *data;
	data = (t_data *) arg;
	pthread_mutex_lock(&data->fork[data->i]);
	printf("philo number %d has taken a fork\n", data->i);
	usleep(data->time_eating);
	printf("philo number %d is eating\n", data->i);
	data->i++;
	pthread_mutex_unlock(&data->fork[data->i]);
	return (NULL);
}

int main(int ac, char **av)
{
	t_data *data;
	int i;

	checker(ac, av);	
	data = malloc(sizeof(t_data));
	data->i = 0;
/*	data.time_eating = 40;
	data.time_sleep = 100;
	data.time_thinking = 100;
	data.time_death = 60;
	data.fork_right = 0;
	data.fork_left = 0;
*/
	i = 0;
	while (i < 4)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	i = 0;
	while(i < 4)
	{
		if((pthread_create(&data->philo[i], NULL, &routine, &data)) != 0)
		{
			printf("failed to create thread");
		}
		i++;
	}
	i = 0;
	while(i < 4)
	{
		//printf("%d\n", i);
		if(pthread_join(data->philo[i], NULL) != 0)
		{
			printf("failed to join thread");
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;	
	}
	return(0);
}