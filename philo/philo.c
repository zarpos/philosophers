/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:34:18 by drubio-m          #+#    #+#             */
/*   Updated: 2024/08/11 20:58:37 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_parse_arguments(argc, argv, &data);
	alloc_mutex(&data);
	init_philos(&data);
	monitor(&data);
	terminate_threads(&data);
	free_misc(&data);
	return (0);
}

/*
ARGUMENTOS
1. number_of_philosophers 
2. time_to_die 
3. time_to_eat
4. time_to_sleep
5. [number_of_times_each_philosopher_must_eat]

*/