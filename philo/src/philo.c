/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 02:10:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 02:10:34 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("Hello my name is \"Philo %d\"\n", philo->number + 1);
	return (NULL);
}
