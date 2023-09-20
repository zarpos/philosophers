/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/20 20:31:35 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Routine for the philos
void	*routine(void *philo_lol)
{
	t_philo	*philo;

	philo = philo_lol;
	printf("Hola soy el thread %d \n", philo->id);
	printf("\n");
	return (NULL);
}

// It initializes the philos struct with the data struct
void	init_philos(t_data	*data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc((sizeof(t_philo) * data->number_of_philosophers) + 1);
	while (i < data->number_of_philosophers)
	{
		philos[i].id = i + 1;
		printf("Id del philo: %d\n", i);
		philos[i].meal_counter = 0;
		printf("Meal count: %d\n", philos[i].meal_counter);
		philos[i].status = 0;
		printf("Estatus del philo: %d\n", philos[i].status);
		philos[i].last_meal = 0;
		printf("Last meal del philo: %llu\n", philos[i].last_meal);
		philos[i].left_fork = NULL;
		printf("Dirección del left fork: %p\n", (void *)philos[i].left_fork);
		philos[i].right_fork = NULL;
		printf("Dirección del right fork: %p\n", (void *)philos[i].right_fork);
		philos[i].print = NULL;
		printf("Dirección del print: %p\n", (void *)philos[i].print);
		philos[i].lock = NULL;
		printf("Dirección del lock: %p\n", (void *)philos[i].lock);
		philos[i].data = data;
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data[i].thread_id, NULL, &routine, &philos[i]);
		printf("Hola soy el philo %d \n", i);
		i++;
	}	
}
