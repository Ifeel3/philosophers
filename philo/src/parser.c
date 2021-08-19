/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:44:15 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 00:44:18 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	error(int errnum)
{
	if (errnum == 1)
		printf("Error: wrong amount of arguments...\n");
	if (errnum == 2)
		printf("Error: wrong argument...\n");
	exit(0);
}

static int	checkargs(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	convert(char *arg)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (arg[i])
	{
		result = (result * 10) + (arg[i] - 48);
		i++;
	}
	return (result);
}

static void	parseargs(char **argv, t_table *table)
{
	table->amount = convert(argv[1]);
	table->time_die = convert(argv[2]);
	table->time_eat = convert(argv[3]);
	table->time_sleep = convert(argv[4]);
	if (argv[5])
		table->must_eat = convert(argv[5]);
	else
		table->must_eat = -1;
}

void	parser(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		error(1);
	if (checkargs(argv))
		error(2);
	parseargs(argv, table);
}
