#include "philo.h"

static void	check_eating(t_table *table)
{
	int i;

	i = 0;
	while (i < table->amount)
	{
		if (table->philos[i].state == 1 && getms(&table->philos[i].last_eat) > table->time_die / 2)
			table->philos[i].state = 0;
		i++;
	}
}

void	*monitor(void *data)
{
	t_table *table;
	int		i;

	i = 0;
	table = (t_table *)data;
	usleep (10000);
	while (1)
	{
//		check_eating(table);
		if (getms(&table->philos[i].last_eat) > 800)
			break ;
		if (i == table->amount - 1)
			i = 0;
		else
			i++;
	}
	pthread_mutex_lock(&table->info);
	printf("%lu %d is dead\n", getms(&table->start), i + 1);
	return (NULL);
}