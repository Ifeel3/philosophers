/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:50:25 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 02:50:26 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	getms(struct timeval *time)
{
	long			result;
	struct timeval	now;

	gettimeofday(&now, NULL);
	result = ((now.tv_sec - time->tv_sec) * 1000)
		+ ((now.tv_usec - time->tv_usec) / 1000);
	return (result);
}
