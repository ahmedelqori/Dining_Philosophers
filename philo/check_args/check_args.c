/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:05:59 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 10:49:38 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_only_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' && j != 0)
				return (0);
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_numbers(int ac, char **av)
{
	if (ft_atoi(av[1]) < 1)
		return (print_return_n(ARG_1_ERROR, 1));
	if (ft_atoi(av[2]) < 0)
		return (print_return_n(ARG_2_ERROR, 1));
	if (ft_atoi(av[3]) < 0)
		return (print_return_n(ARG_3_ERROR, 1));
	if (ft_atoi(av[4]) < 0)
		return (print_return_n(ARG_4_ERROR, 1));
	if (ac == 6 && ft_atoi(av[5]) < 0)
		return (print_return_n(ARG_5_ERROR, 1));
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_return_n(ARG_FORMAT, 1));
	if (check_only_digit(ac, av) == 0)
		return (print_return_n(ARG_ONLY_DIGIT, 1));
	if (check_numbers(ac, av))
		return (1);
	return (0);
}
