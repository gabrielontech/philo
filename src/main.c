/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:05:41 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 15:09:44 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data		data;
	long long	process_time;

	process_time = 0;
	checker(ac, av);
	if (ft_atoi(av[1]) == 1)
	{
		data.die_time = ft_atoi(av[2]);
		process_time = timestamp();
		unique(data.die_time, process_time);
		return (0);
	}
	init_all(&data, av);
	philo_pthread(&data);
	return (0);
}
