/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:25:30 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 00:25:33 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				number;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	struct timeval	start;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*info;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	int				amount;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	struct timeval	start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	info;
	pthread_t		monitor;
}					t_table;

void	parser(int argc, char **argv, t_table *table);
void	init(t_table *table);
void	*philo(void *data);
#endif
