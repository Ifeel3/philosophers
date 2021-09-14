/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:52:54 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/23 09:53:15 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				index;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				time_die;
	int				count;
	int				is_dead;
	struct timeval	start;
	struct timeval	last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	is_eat;
	pthread_mutex_t	*info;
}	t_philo;

typedef struct s_table
{
	int				amount;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	struct timeval	start;
	pthread_mutex_t	info;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		*monitors;
	pthread_t		main_monitor;
}		t_table;

int		ft_atoi(const char *str);
int		parser(int argc, char **argv, t_table *table);
int		init(t_table *table);
long	getms(struct timeval *time);
void	*philo(void *data);
void	*monitor(void *data);
void	*main_monitor(void *data);
void	my_sleep(long time);
#endif
