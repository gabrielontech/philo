/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:14:19 by gkitoko           #+#    #+#             */
/*   Updated: 2022/07/25 10:39:47 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include <stddef.h>
#include <string.h>

typedef struct s_data
{
	pthread_t philo[4];
	pthread_mutex_t fork[4];
	uint64_t time_eating;
	uint64_t time_sleep;
	uint64_t time_thinking;
	uint64_t time_death;
	int fork_right;
	int fork_left;
	int i;
} t_data;

// UTILS //
int	ft_isdigit(int c);
void	check_is_digit(int ac, char **av);
void	checker(int ac, char **av);
void	check_is_valid(char **av);
// UTILS //
long int	ft_atoi(char *str);
size_t	ft_strlen(char *str);

#endif