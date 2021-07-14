#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->args = parser(argc, argv);
	philoinit(data);
	pause();
}
