/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:41:42 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 13:41:56 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print(t_data *data, t_philo *philo, char *msg, char *color)
{
	pthread_mutex_lock(&data->done);
	if (philo->done == 0)
		printf("%s%lld \t%d\t%s\n", color, gettime(data), philo->id, msg);
	pthread_mutex_unlock(&data->done);
}
