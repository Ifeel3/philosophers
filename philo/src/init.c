/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:45:14 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 01:45:16 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_init(t_table *table)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->amount);
	i = 0;
	while (i < table->amount)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->info, NULL);
}

static void	params(t_table *table, int i)
{
	table->philos[i].number = i;
	table->philos[i].time_die = table->time_die;
	table->philos[i].time_eat = table->time_eat;
	table->philos[i].time_sleep = table->time_sleep;
	table->philos[i].must_eat = table->must_eat;
	table->philos[i].left = &table->forks[i];
	if (i == table->amount - 1)
		table->philos[i].right = &table->forks[0];
	else
		table->philos[i].right = &table->forks[i + 1];
	table->philos[i].info = &table->info;
	table->philos[i].start = table->start;
	pthread_create(&table->philos[i].thread, NULL,
		   philo, &table->philos[i]);
	pthread_detach(table->philos[i].thread);
}

static void	philo_init(t_table *table)
{
	int	i;

	gettimeofday(&table->start, NULL);
	i = 0;
	while (i < table->amount)
	{
		params(table, i);
		i++;
	}
}

void	init(t_table *table)
{
	mutex_init(table);
	philo_init(table);
}
