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
	t_table	table;

	if (parser(argc, argv, &table) == 0)
		return (0);
	if (init(&table) == 0)
		return (0);
	pthread_create(&table.main_monitor, NULL, main_monitor, &table);
	pthread_join(table.main_monitor, NULL);
	return (0);
}
