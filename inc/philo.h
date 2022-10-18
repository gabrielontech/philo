/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:14:19 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 15:03:29 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <stddef.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				did_eat;
	int				left_fork;
	int				right_fork;
	pthread_t		philo_pth;
	long long		last_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	double			die_time;
	double			eat_time;
	double			sleep_time;
	double			nb_of_eat;
	bool			all_ate;
	long long		time_stamp;
	struct s_philo	philo[200];
	pthread_mutex_t	fork[200];
	pthread_mutex_t	meal;
	pthread_mutex_t	write;
	pthread_mutex_t	is_dead;
	bool			dead;
}	t_data;
// UTILS //
int			ft_isdigit(int c);
void		check_is_digit(int ac, char **av);
void		checker(int ac, char **av);
void		check_is_valid(char **av);
// UTILS //
long int	ft_atoi(char *str);
size_t		ft_strlen(char *str);
// TIME_MANAGEMENT //
void		wait_action(long long time);
long long	timediff(long long start, long long end);
long long	timestamp(void);
// UNIQUE PHILO //
void		unique(long int die_time, long long process_time);
// MANAGEMENT //
void		init_philo(t_data *data);
void		init_mutex(t_data *data);
void		init_all(t_data *data, char **av);
void		*routine(void *args);
void		philo_pthread(t_data *data);
void		eat(t_philo *philo);
void		routine_extend(t_philo *philo, t_data *data);
void		philo_talk(t_data *data, t_philo *philo, char *message);
void		check_alive(t_data *data, t_philo *philo);
void		check_alive_extend(t_data *data, t_philo *philo, int i);
void		exit_phtread(t_data *data, t_philo *philo);

#endif