#include "philo_bonus.h"

int	timeafterstart(struct timeval start)
{
	int				result;
	struct timeval	now;

	gettimeofday(&now, (void *)0);
	result = (int)((now.tv_sec * 1000000 + now.tv_usec)
			- (start.tv_sec * 1000000 + start.tv_usec)) / 10000;
	return (result);
}
