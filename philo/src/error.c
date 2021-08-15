#include "philo.h"

void	error(int errornum)
{
	if (errornum == 1)
		printf("Error: arguments must be from 4 to 5...\n");
	if (errornum == 2)
		printf("Error: not valid argument...\n");
	exit(0);
}
