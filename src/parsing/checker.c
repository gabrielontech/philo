/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:28:11 by gkitoko           #+#    #+#             */
/*   Updated: 2022/07/25 10:38:53 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	check_is_valid(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		if(strlen(av[i]) > 10)
			return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
		if (ft_atoi(av[i]) < 0 || ft_atoi(av[i]) > INT_MAX)
			return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
		i++;
	}
}

void	check_is_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!(ft_strlen(av[i])))
			return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
		if (av[i][j] == '+')
			j++;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j])))
				return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
			j++;
		}
		i++;
	}
}

void	checker(int ac, char **av)
{
	if (ac < 2)
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
	else if (ac == 5)
	{
		check_is_digit(ac, av);
		check_is_valid(av);
	}else if (ac == 6)
	{
		check_is_digit(ac, av);
		check_is_valid(av);
	}
	else
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE));		
}