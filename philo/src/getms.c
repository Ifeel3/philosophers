/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:36:28 by lvallie           #+#    #+#             */
/*   Updated: 2021/09/11 20:36:31 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	getms(struct timeval *time)
{
	struct timeval	now;
	long			result;

	gettimeofday(&now, NULL);
	result = (now.tv_sec - time->tv_sec) * 1000
		+ (now.tv_usec - time->tv_usec) / 1000;
	return (result);
}

void	my_sleep(long time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (getms(&start) < time)
		usleep(10);
}
