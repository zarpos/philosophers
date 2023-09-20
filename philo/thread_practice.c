/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/20 11:33:55 by drubio-m         ###   ########.fr       */
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
		philos[i].meal_counter = 0;
		philos[i].status = 0;
		philos[i].last_meal = 0;
		philos[i].left_fork = NULL;
		philos[i].right_fork = NULL;
		philos[i].print = NULL;
		philos[i].lock = NULL;
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
