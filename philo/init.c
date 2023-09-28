/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/28 13:55:05 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Routine for the philos
void	*routine(void *philo_no_casted)
{
	t_philo	*philo;

	philo = philo_no_casted;
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
	if (!philos)
		ft_error("Failed to alloc memory for philos");
	while (i < data->number_of_philosophers)
	{
		philos[i].id = i + 1;
		printf("Id del philo: %d\n", philos[i].id);
		philos[i].meal_counter = 0;
		printf("Meal count: %d\n", philos[i].meal_counter);
		philos[i].status = 0;
		printf("Estatus del philo: %d\n", philos[i].status);
		philos[i].last_meal = 0;
		printf("Last meal del philo: %llu\n", philos[i].last_meal);
		philos[i].left_fork = NULL;
		philos[i].right_fork = NULL;
		philos[i].print = NULL;
		philos[i].lock = NULL;
		philos[i].data = data;
		i++;
	}
	i = 0;
	while (i++ < data->number_of_philosophers)
	{
		printf("\n");
		printf("Esto vale i justo ahora: %d\n", i);
		printf("\n");
		pthread_create(&data[i].thread_id, NULL, &routine, &philos[i]);
		printf("Hola soy el philo %d \n", i);
	}	
	init_mutex(philos, data);
}

// In this function we will alloc memory for the mutex and initiate them
void	alloc_mutex(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].left_fork)
			ft_error("Failed to allloc memory for fork");
		printf("Dirección del left fork(%d): %p\n\n", philo[i].id, (void *)philo[i].left_fork);
		philo[i].right_fork = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].right_fork)
			ft_error("Failed to allloc memory for fork");
		printf("Dirección del right fork(%d): %p\n\n", philo[i].id, (void *)philo[i].right_fork);
		philo[i].print = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].print)
			ft_error("Failed to alloc memory for print");
		printf("Dirección del print(%d): %p\n\n", philo[i].id, (void *)philo[i].print);
		philo[i].lock = malloc(sizeof(pthread_mutex_t));
		if (!philo[i].lock)
			ft_error("Failed to alloc memory for lock");
		printf("Dirección del lock(%d): %p\n\n", philo[i].id, (void *)philo[i].lock);
		i++;
	}
}

// In this function we will initiate the mutexs allocated before
void	init_mutex(t_philo *philo, t_data *data)
{
	pthread_mutex_init(&philo->left_fork, NULL);
	pthread_mutex_init(&philo->right_fork, NULL);
	pthread_mutex_init(&philo->print, NULL);
	pthread_mutex_init(&philo->lock, NULL);
}
