/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:10:12 by ael-qori          #+#    #+#             */
/*   Updated: 2024/04/23 09:34:45 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_return_n(char *msg, int n)
{
	printf(BOLDRED "\n%s\n", msg);
	return (n);
}

void	*print_return_null(char *msg)
{
	printf(BOLDRED "\n%s\n", msg);
	return (NULL);
}
