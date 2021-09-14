/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:36:14 by lvallie           #+#    #+#             */
/*   Updated: 2021/09/11 20:36:17 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(&philo->is_eat);
		if (getms(&philo->last_eat) > philo->time_die
			&& philo->count != philo->must_eat)
			break ;
		pthread_mutex_unlock(&philo->is_eat);
		my_sleep(10);
	}
	pthread_mutex_lock(philo->info);
	printf("%lu %d is dead\n", getms(&philo->start), i + 1);
	philo->is_dead = 1;
	return (NULL);
}

static int	check_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->amount)
	{
		if (table->philos[i].count != table->must_eat)
			return (0);
		i++;
	}
	return (1);
}

static int	check_dead(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->amount)
	{
		if (table->philos[i].is_dead)
			return (1);
		i++;
	}
	return (0);
}

void	*main_monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	i = 0;
	while (1)
	{
		if (check_dead(table))
			break ;
		if (check_full(table))
		{
			pthread_mutex_lock(&table->info);
			printf("All philosophers are full\n");
			break ;
		}
		usleep(300);
	}
	return (NULL);
}
