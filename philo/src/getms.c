#include "philo.h"

long	getms(struct timeval *time)
{
	struct timeval	now;
	long			result;

	gettimeofday(&now, NULL);
	result = (now.tv_sec - time->tv_sec) * 1000
			+ (now.tv_usec - time->tv_usec) / 1000;
	return (result);
}