/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:44:28 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 17:09:03 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	wait_action(long long time)
{
	long long	i;

	i = timestamp();
	while (1)
	{
		if (timediff(i, timestamp()) >= time)
			break ;
		usleep(100);
	}
}
