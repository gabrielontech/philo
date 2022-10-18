/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:34:46 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 17:09:09 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	unique(long int die_time, long long process_time)
{
	printf("%lli ", timestamp() - process_time);
	printf("1 has taken a fork\n");
	wait_action(die_time);
	printf("%lli ", timestamp() - process_time);
	printf("1 died\n");
}
