/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:38:03 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 10:14:04 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long long time)
{
	t_time		s_time;
	t_time		c_time;
	long long	start;
	long long	current;

	gettimeofday(&s_time, NULL);
	start = ((s_time.tv_sec * 1000) + (s_time.tv_usec / 1000));
	while (1)
	{
		gettimeofday(&c_time, NULL);
		current = ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
		if (current - start >= time)
			break ;
		usleep(50);
	}
}

long long	gettime(t_data *data)
{
	t_time		time;
	long long	current;

	gettimeofday(&time, NULL);
	current = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (current - data->start_time);
}
