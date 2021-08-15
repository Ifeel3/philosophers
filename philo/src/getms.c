#include "../philo.h"

int	getms(struct timeval *start)
{
	struct timeval	now;
	int				result;

	gettimeofday(&now, NULL);
	result = (int)((now.tv_sec * 1000 + now.tv_usec / 1000)
			- (start->tv_sec * 1000 + start->tv_usec / 1000));
	return (result);
}
