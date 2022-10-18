/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <gkitoko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:28:11 by gkitoko           #+#    #+#             */
/*   Updated: 2022/10/18 17:06:46 by gkitoko          ###   ########.fr       */
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
		if (ft_strlen(av[i]) > 10)
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
	if (ac != 5 && ac != 6)
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
	check_is_digit(ac, av);
	check_is_valid(av);
}
