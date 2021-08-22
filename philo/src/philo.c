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

static void	p_print(t_philo *philo, char *string)
{
	unsigned int	ms;

	ms = getms(&philo->start);
	pthread_mutex_lock(philo->info);
	printf("%d %d %s\n", ms, philo->number + 1, string);
	pthread_mutex_unlock(philo->info);
}

static void	p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	p_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right);
	p_print(philo, "is start eating");
	gettimeofday(&philo->last_eat, NULL);
	usleep((philo->time_eat) * 1000);
	philo->count++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

static void	p_sleep(t_philo *philo)
{
	p_print(philo, "is sleeping");
	usleep((philo->time_sleep) * 1000);
	p_print(philo, "is thinking");
}

void	*philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->count = 0;
	if (philo->number % 2 != 0)
		usleep(1000);
	while (philo->count != philo->must_eat)
	{
		p_eat(philo);
		p_sleep(philo);
	}
	return (NULL);
}
