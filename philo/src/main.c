#include "../philo.h"

int	main(int argc, char **argv)
{
	struct timeval	start;
	t_data			data;

	parser(argc, argv, &data);
	gettimeofday(&start, NULL);
	printf("Philos = %d\n", data.philos);
	printf("Time to die = %d\n", data.timedie);
	printf("Time to eat = %d\n", data.timeeat);
	printf("Time to sleep = %d\n", data.timesleep);
	printf("Must eat = %d\n", data.musteat);
	return (0);
}
