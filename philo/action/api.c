/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:36 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 13:27:19 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	everyone_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->eat);
	if (philo->how_many_eat == data->number_philo_must_eat && philo->mark == 0)
	{
		philo->mark = 1;
		data->everyone_eat++;
	}
	pthread_mutex_unlock(&data->eat);
}

void	is_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->done);
	philo->done = 1;
	printf("%s%lld ms\t%d\t%s\n", BOLDRED, gettime(data), philo->id, DEAD);
	pthread_mutex_unlock(&data->done);
}

void	all_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->done);
	philo->done = 1;
	printf(BOLDBLUE"<<<<< Every One Eat >>>>>");
	pthread_mutex_unlock(&data->done);
}

void	tell_anyone_to_stop(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->number_of_philo)
	{
		philo = &data->philosophers[i];
		pthread_mutex_lock(&data->done);
		philo->done = 1;
		pthread_mutex_unlock(&data->done);
		i++;
	}
}

void	*api(void *args)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)args;
	while (1)
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			philo = &data->philosophers[i];
			everyone_eat(data, philo);
			pthread_mutex_lock(&data->time);
			if ((gettime(data) - philo->last_meal) > data->time_to_die)
				return (help_api(data, philo));
			else
			{
				if (help_again_api(data, philo))
					return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
