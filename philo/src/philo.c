#include "philo.h"

static void	p_print(t_philo *philo, char *string)
{
	pthread_mutex_lock(philo->info);
	printf("%lu %d %s\n", getms(&philo->start), philo->index + 1, string);
	pthread_mutex_unlock(philo->info);
}

static void	p_eat(t_philo *philo)
{
//	while (philo->state != 0)
//		;
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->left);
		p_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right);
	}
	else
	{
		pthread_mutex_lock(philo->right);
		p_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->left);
	}
	p_print(philo, "is eating");
	gettimeofday(&philo->last_eat, NULL);
	philo->count++;
	philo->state = 1;
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

static void	p_sleep(t_philo *philo)
{
	p_print(philo, "is sleeping");
	usleep(philo->time_sleep * 1000);
	p_print(philo, "is thinking");
}


void	*philo(void *data)
{
	t_philo	*philo;
	philo = (t_philo *)data;
	while (philo->count != philo->must_eat)
	{
		p_eat(philo);
		p_sleep(philo);
	}
	return (NULL);
}