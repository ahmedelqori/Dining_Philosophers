/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:21:38 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 10:59:03 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_args(ac, av))
		return (1);
	data = ft_calloc(1, sizeof(t_data), ALLOC_FAIL_DATA);
	if (data == NULL)
		return (1);
	if (init_data(data, av) == 1)
		return (1);
	action(data);
	free(data->forks);
	free(data->philosophers);
	free(data);
	return (0);
}
