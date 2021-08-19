/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 00:21:10 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/20 00:21:16 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	parser(argc, argv, &table);
	printf("amount = %d\n", table.amount);
	printf("time to die = %d\n", table.time_die);
	printf("time to sleep = %d\n", table.time_sleep);
	printf("time to eat = %d\n", table.time_eat);
	printf("must eat = %d\n", table.must_eat);
	return (0);
}
