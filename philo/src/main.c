/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:21:10 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 00:21:16 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_done(t_table *table)
{
	int	i;

	i = 0;
	while (i <= table->amount - 1)
	{
		if (table->philos[i].count != table->must_eat)
			return (0);
		if (i == table->amount - 1)
			return (1);
		i++;
	}
	return (0);
}

static void	*monitor(void *data)
{
	t_table	*table;
	int		i;
	long	time;

	table = (t_table *)data;
	i = 0;
	while (1)
	{
		time = getms(&table->philos[i].last_eat);
		if (time > table->time_die && table->philos[i].count != table->must_eat)
			break ;
		if (i < table->amount - 1)
			i++;
		else
			i = 0;
		if (check_done(table))
		{
			printf("All philosophers are full\n");
			return (NULL);
		}
		usleep(1000);
	}
	pthread_mutex_lock(&table->info);
	printf("%zu %d is dead\n", getms(&table->start), i + 1);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (parser(argc, argv, &table))
		return (0);
	init(&table);
	pthread_create(&table.monitor, NULL, monitor, &table);
	pthread_join(table.monitor, NULL);
	return (0);
}
