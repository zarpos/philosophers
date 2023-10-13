/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:34:18 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/13 21:13:59 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_parse_arguments(argc, argv, &data);
	alloc_mutex(&data);
//	printf("%p\n", data.philo);
//	printf("%p\n", data.thread_id);
//	printf("%p\n", data.forks);
//	printf("%p\n", data.lock);
//	printf("%p\n", data.print);
	//printf("%llu\n", data.start_time);

//	printf("Memoria alocada\n");

//	pthread_mutex_lock(data.print);
//	printf("print lockeado\n");
	init_philos(&data);
//	printf("philos iniciados\n");
//	pthread_mutex_unlock(data.print);
//	printf("Print deslockeado\n");
	//terminate_threads(&data);
//	printf("Hilos terminados\n");
//	free_misc(&data);
//	printf("Morralla borrada\n");
	//printf("Philos iniciados\n");
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