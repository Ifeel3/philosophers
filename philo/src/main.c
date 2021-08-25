/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:53:27 by lvallie           #+#    #+#             */
/*   Updated: 2021/08/23 09:53:29 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table table;

	if (parser(argc, argv, &table) == 0)
		return (0);
	printf("amount = %d\n", table.amount);
	printf("time_die = %d\n", table.time_die);
	printf("time_eat = %d\n", table.time_eat);
	printf("time_sleep = %d\n", table.time_sleep);
	printf("must_eat = %d\n", table.must_eat);
	return (0);
}
