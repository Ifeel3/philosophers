#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "pthread.h"

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}	t_philo;

typedef struct s_data
{
	int		*args;
	t_philo	*philos;
}	t_data;

int		timeafterstart(struct timeval start);
int		*parser(int argc, char **argv);
void	philoinit(t_data *data);
void	philocreate(t_data *data);
#endif