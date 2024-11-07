/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:59:37 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 09:34:51 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philosophers[i].mark = 0;
		data->philosophers[i].id = i + 1;
		data->philosophers[i].mark = 0;
		data->philosophers[i].left_fork = i;
		data->philosophers[i].right_fork = i + 1;
		if (data->philosophers[i].id == data->number_of_philo)
		{
			data->philosophers[i].left_fork = 0;
			data->philosophers[i].right_fork = i;
		}
		data->philosophers[i].last_meal = 0;
		data->philosophers[i].how_many_eat = 0;
		i++;
	}
}
