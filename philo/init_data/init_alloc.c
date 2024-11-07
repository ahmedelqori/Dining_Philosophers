/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:51:39 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 09:34:59 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_alloc(t_data *data)
{
	data->forks = ft_calloc(data->number_of_philo,
			sizeof(pthread_mutex_t), ALLOC_FAIL_MUTEX_FORKS);
	if (data->forks == NULL)
	{
		free(data);
		return (1);
	}
	data->philosophers = ft_calloc(data->number_of_philo,
			sizeof(t_philo), ALLOC_FAIL_THREADS);
	if (data->philosophers == NULL)
	{
		free(data->forks);
		free(data);
		return (1);
	}
	return (0);
}
