/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru.     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 01:42:45 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/26 01:42:47 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(char **argv)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	parse_args(char **argv, t_table *table)
{
	table->amount = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
}

int	parser(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments...\n");
		return (0);
	}
	if (check_args(argv) == 0)
	{
		printf("Error: invalid argument...\n");
		return (0);
	}
	parse_args(argv, table);
	return (1);
}
