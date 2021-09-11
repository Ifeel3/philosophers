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

static int	find_min_count(t_table *table)
{
	int	i;
	int	min;

	i = 0;
	min = table->philos[0].count;
	while (i < table->amount)
	{
		if (table->philos[i].count < min)
			min = table->philos[i].count;
		i++;
	}
	return (min);
}

static int	check_end(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->amount)
	{
		if (table->philos[i].count != table->must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&table->info);
	printf("all philosophers are full\n");
	return (1);
}

void	*monitor(void *data)
{
	t_table	*table;
	int		i;

	i = 0;
	table = (t_table *)data;
	while (1)
	{
		if (getms(&table->philos[i].last_eat) > table->time_die
			&& table->philos[i].count != table->must_eat)
			break ;
		if (table->philos[i].count <= find_min_count(table))
			table->philos[i].pause = 0;
		if (i == table->amount - 1)
			i = 0;
		else
			i++;
		if (check_end(table))
			return (NULL);
		my_sleep(1);
	}
	pthread_mutex_lock(&table->info);
	printf("%lu %d is dead\n", getms(&table->start), i + 1);
	return (NULL);
}
