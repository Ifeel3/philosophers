/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:35:59 by lvallie           #+#    #+#             */
/*   Updated: 2021/09/11 20:36:03 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_print(t_philo *philo, char *string)
{
	pthread_mutex_lock(philo->info);
	printf("%lu %d %s\n", getms(&philo->start), philo->index + 1, string);
	pthread_mutex_unlock(philo->info);
}

static void	p_eat(t_philo *philo)
{
	while (philo->pause == 1)
		;
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		p_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		p_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
	}
	gettimeofday(&philo->last_eat, NULL);
	p_print(philo, "is eating");
	philo->pause = 1;
	philo->count++;
	my_sleep(philo->time_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

static void	p_sleep(t_philo *philo)
{
	p_print(philo, "is sleeping");
	my_sleep(philo->time_sleep);
	p_print(philo, "is thinking");
}

void	*philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->count != philo->must_eat)
	{
		p_eat(philo);
		p_sleep(philo);
	}
	return (NULL);
}
