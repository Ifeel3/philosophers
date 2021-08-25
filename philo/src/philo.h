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

typedef struct s_table
{
	int	amount;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int must_eat;
}		t_table;

int	ft_atoi(const char *str);
int	parser(int argc, char **argv, t_table *table);

#endif
