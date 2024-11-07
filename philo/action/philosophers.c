/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:17:24 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/24 18:05:47 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*handle_one_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	printf("%s%lld \t%d\t%s\n", BOLDYELLOW, gettime(data), philo->id, FORK);
	ft_usleep(data->time_to_die);
	printf("%s%lld \t%d\t%s\n", BOLDRED, gettime(data), philo->id, DEAD);
	return (NULL);
}

void	hold_fork(t_data *data, t_philo *philo, int fork)
{
	pthread_mutex_lock(&data->forks[fork]);
	print(data, philo, FORK, BOLDYELLOW);
}

void	eating(t_data *data, t_philo *philo)
{
	print(data, philo, EAT, BOLDMAGENTA);
	ft_usleep(data->time_to_eat);
	pthread_mutex_lock(&data->time);
	philo->last_meal = gettime(data);
	pthread_mutex_unlock(&data->time);
	pthread_mutex_lock(&data->eat);
	philo->how_many_eat++;
	pthread_mutex_unlock(&data->eat);
}

void	sleeping(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	print(data, philo, SLEEP, BOLDGREEN);
	ft_usleep(data->time_to_sleep);
	print(data, philo, THINK, BOLDCYAN);
}

void	*philosophers(void *arg)
{
	static int	i = 0;
	t_data		*data;
	t_philo		*philo;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->increment);
	philo = &data->philosophers[i++];
	pthread_mutex_unlock(&data->increment);
	if (philo->id % 2 == 0)
		ft_usleep(15);
	while (1)
	{
		pthread_mutex_lock(&data->done);
		if (philo->done == 1)
		{
			pthread_mutex_unlock(&data->done);
			break ;
		}
		if (data->number_of_philo == 1)
			return (handle_one_philo(data, philo));
		pthread_mutex_unlock(&data->done);
		start_action(data, philo);
	}
	return (NULL);
}
