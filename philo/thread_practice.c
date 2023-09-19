/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/19 17:54:30 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Routine for the philos
void	*routine(void *philo_lol)
{
	t_philo	*philo;

	philo = philo_lol;
	printf("Estoy en antes del printf del id de philo\n");
	printf("Hola soy el philo :%d\n", philo->id);
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
		printf("Voy a hacer una asignación entera a la estructura philo\n");
		philos[i].id = i + 1;
		printf("Este es el id del philo recien creado :%d\n", philos[i].id);
		philos[i].meal_counter = 0;
		printf("Este es el meal count del philo recien creado :%d\n", philos[i].meal_counter);
		philos[i].status = 0;
		printf("Este es el status del philo recien creado :%d\n", philos[i].status);
		philos[i].last_meal = 0;
		printf("Este es el last meal del philo recien creado :%llu\n", philos[i].last_meal);
		philos[i].left_fork = NULL;
		printf("Acabo de asignar a left_fork\n");
		philos[i].right_fork = NULL;
		printf("Acabo de asignar a right_fork\n");
		philos[i].print = NULL;
		printf("Acabo de asignar a print\n");
		philos[i].lock = NULL;
		printf("Acabo de asignar a lock\n");
		philos[i].data = data;
		printf("Acabo de asignar a data\n");
		printf("\n");
		i++;
	}
	printf("Acabo de hacer una asignación entera a la estructura philo\n");
	i = 0;
	while (i < data->number_of_philosophers)
	{
		printf("voy a llamar a la función de crear hilo\n");
		pthread_create(&data[i].thread_id, NULL, &routine, &philos[i]);
		printf("Ya he llamado a la función de crear hilo\n");
		printf("\n");
		i++;
	}	
}
