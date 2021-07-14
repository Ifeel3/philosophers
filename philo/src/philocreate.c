#include "philo.h"

static void	*test(t_data *data)
{
	t_data	*tmp;
	int		num;

	tmp = data;
	num = tmp->count;
	while (1)
	{
		pthread_mutex_lock(&tmp->fork[num]);
		pthread_mutex_lock(&tmp->fork[num + 1]);
		printf("philo %d dining\n", num);
		sleep(3);
		pthread_mutex_unlock(&tmp->fork[num]);
		pthread_mutex_unlock(&tmp->fork[num + 1]);
		sleep(10);
	}
	return (NULL);
}

void	philocreate(t_data *data)
{
	int	i;

	i = 0;
	data->count = i;
	while (i < data->args[0])
	{
		pthread_create(&data->philos[i], NULL, (void *)test, data);
		i++;
		data->count = i;
	}
}