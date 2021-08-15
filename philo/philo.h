#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data
{
	int	philos;
	int	timedie;
	int	timeeat;
	int	timesleep;
	int	musteat;
}		t_data;

int		getms(struct timeval *start);
void	error(int errornum);
void	parser(int argc, char **argv, t_data *data);
#endif