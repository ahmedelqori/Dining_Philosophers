/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:47:56 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 09:34:56 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	free_init_data(t_data *data)
{
	free(data->forks);
	free(data->philosophers);
	free(data);
}

static void	init_inputs(t_data *data, char **av)
{
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->number_philo_must_eat = -1;
	if (av[5])
		data->number_philo_must_eat = ft_atoi(av[5]);
}

int	init_data(t_data *data, char **av)
{
	init_inputs(data, av);
	if (init_alloc(data))
		return (1);
	if (init_mutex(data) == 1)
	{
		free_init_data(data);
		return (1);
	}
	init_philos(data);
	return (0);
}
