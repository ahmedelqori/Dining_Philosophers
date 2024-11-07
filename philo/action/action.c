/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:13:11 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 13:21:21 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_action(t_data *data, t_philo *philo)
{
	hold_fork(data, philo, philo->left_fork);
	hold_fork(data, philo, philo->right_fork);
	eating(data, philo);
	sleeping(data, philo);
}

void	*help_api(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&data->time);
	is_dead(data, philo);
	tell_anyone_to_stop(data);
	return (NULL);
}

int	help_again_api(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&data->time);
	pthread_mutex_lock(&data->eat);
	if (data->everyone_eat == data->number_of_philo)
	{
		pthread_mutex_unlock(&data->eat);
		all_eat(data, philo);
		tell_anyone_to_stop(data);
		return (1);
	}
	else
		pthread_mutex_unlock(&data->eat);
	return (0);
}

void	action(t_data *data)
{
	int			i;
	t_time		time;
	pthread_t	monitor;

	i = 0;
	gettimeofday(&time, NULL);
	data->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (data->number_philo_must_eat == 0)
		return ;
	data->everyone_eat = 0;
	pthread_create(&monitor, NULL, &api, data);
	pthread_detach(monitor);
	while (i < data->number_of_philo)
	{
		pthread_mutex_lock(&data->time);
		data->philosophers[i].last_meal = data->start_time;
		pthread_mutex_unlock(&data->time);
		pthread_create(&data->philosophers[i].thread, NULL, philosophers, data);
		i++;
	}
	i = -1;
	while (++i < data->number_of_philo)
		pthread_join(data->philosophers[i].thread, NULL);
}
