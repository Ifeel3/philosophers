#include "philo_bonus.h"

int main()
{
	struct timeval start;
	int	time;

	gettimeofday(&start, (void *)0);
	sleep(1);
	time = timeafterstart(start);
	printf("Philo_bonus!\n");
	printf("time = %d\n", time);
	return 0;
}
