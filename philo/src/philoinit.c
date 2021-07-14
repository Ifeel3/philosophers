#include "philo.h"

void	philoinit(t_data *data)
{
	int	i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->args[0]);
	if (!data->philos)
	{
		printf("Error: philos not created...\n");
		exit(0);
	}
	i = 0;
	while (i < data->args[0])
	{
		pthread_mutex_init(&data->philos[i].left, NULL);
		i++;
	}
	i = 0;
	while (data->philos[i + 1] != NULL)
	{
		data->philos[i].right = &data->philos[i + 1].left;
		i++;
	}
}
