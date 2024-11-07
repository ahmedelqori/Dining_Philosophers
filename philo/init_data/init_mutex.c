/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:55:46 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 10:43:42 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	destroy_in_loop(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
		pthread_mutex_destroy(&data->forks[i++]);
	return (1);
}

static int	destroy_and_print_error(t_data *data, int i, int n)
{
	printf(BOLDRED "\n%s\n", FAIL_MUTEX);
	destroy_in_loop(data, i);
	if (n == 1)
		return (1);
	else if (n == 2)
		pthread_mutex_destroy(&data->increment);
	else if (n == 3)
	{
		pthread_mutex_destroy(&data->increment);
		pthread_mutex_destroy(&data->done);
	}
	else if (n == 4)
	{
		pthread_mutex_destroy(&data->increment);
		pthread_mutex_destroy(&data->done);
		pthread_mutex_destroy(&data->time);
	}
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf(BOLDRED "\n%s\n", FAIL_MUTEX);
			return (destroy_in_loop(data, i));
		}
	}
	if (pthread_mutex_init(&data->increment, NULL) != 0)
		return (destroy_and_print_error(data, i, 1));
	if (pthread_mutex_init(&data->done, NULL) != 0)
		return (destroy_and_print_error(data, i, 2));
	if (pthread_mutex_init(&data->time, NULL) != 0)
		return (destroy_and_print_error(data, i, 3));
	if (pthread_mutex_init(&data->eat, NULL) != 0)
		return (destroy_and_print_error(data, i, 4));
	return (0);
}
