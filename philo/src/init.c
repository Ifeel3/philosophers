/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:23:20 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/26 14:23:22 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_init(t_table *table)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->amount);
	if (!table->forks)
	{
		printf("Error: memory not allocated for mutex...\n");
		return (0);
	}
	i = 0;
	while (i < table->amount)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->info, NULL);
	return (1);
}

static void	philo_fill(t_table *table, t_philo *philo)
{
	philo->must_eat = table->must_eat;
	philo->time_sleep = table->time_sleep;
	philo->time_eat = table->time_eat;
	philo->count = 0;
	philo->left = &table->forks[philo->index];
	if (philo->index == table->amount - 1)
		philo->right = &table->forks[0];
	else
		philo->right = &table->forks[philo->index + 1];
	philo->info = &table->info;
	philo->state = 0;
}

static int	philo_init(t_table *table)
{
	int	i;

	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->amount);
	if (!table->philos)
	{
		printf("Error: memory not allocated for philos...\n");
		return (0);
	}
	i = 0;
	while (i < table->amount)
	{
		table->philos[i].index = i;
		philo_fill(table, &table->philos[i]);
		i++;
	}
	return (1);
}

static void	philo_start(t_table *table)
{
	int	i;

	i = 0;
	gettimeofday(&table->start, NULL);
	while (i < table->amount)
	{
		table->philos[i].start = table->start;
		table->philos[i].last_eat = table->start;
		pthread_create(&table->philos[i].thread, NULL, philo, &table->philos[i]);
		pthread_detach(table->philos[i].thread);
		i++;
	}
	pthread_create(&table->monitor, NULL, monitor, table);
}

int	init(t_table *table)
{
	if (mutex_init(table) == 0)
		return (0);
	if (philo_init(table) == 0)
		return (0);
	philo_start(table);
	return (1);
}
