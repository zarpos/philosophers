/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/05 17:41:48 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Routine for the philos
void	*routine(void *philo_no_casted)
{
	t_philo	*philo;

	philo = philo_no_casted;
	printf("Hola soy el philo %d\n", philo->id);
	return (NULL);
}

void	alloc_mutex(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philo)
		ft_error("Failed to alloc memory");
	data->thread_id = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->thread_id)
		ft_error("Failed to alloc memory");
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		ft_error("Failed to alloc memory");
	data->lock = malloc(sizeof(pthread_mutex_t) * sizeof(data->nb_philos));
	if (!data->lock)
		ft_error("Failed to alloc memory");
	data->print = malloc(sizeof(pthread_mutex_t) * 1);
	if (!data->print)
		ft_error("Failed to alloc memory");
	data->start_time = set_time();
}

// In this function we initiate the mutex and asign the forks 
// for the diferent philos using our lovely friend, MATHS ;)
void	init_mutex(t_data *data, int i)
{
	if (pthread_mutex_init(data->lock, NULL))
		return ;
	data->philo[i].lock = &data->lock[i];
	if (pthread_mutex_init(data->print, NULL))
		return ;
	data->philo[i].print = data->print;
	if (pthread_mutex_init(data->forks, NULL))
	data->philo[i].left_fork = &data->forks[i];
	data->philo[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
}

// In this function we will initiate all the variables of the philos
// And also create all the threads for the different philos
void	init_philos(t_data	*data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		init_mutex(data, i);
		data->philo[i].id = i + 1;
		data->philo[i].meal_counter = 0;
		data->philo[i].status = 0;
	}
	i = -1;
	while (++i < data->nb_philos)
		pthread_create(&(data->thread_id[i]), NULL, routine, &(data->philo[i]));
}

/*
COSAS QUE TENGO QUE HACER:

1. Hacer la parte de iniciar los mutex con el array que le he pasado en la iniciar philos
2. Una vez haya hecho eso, toca iniciar el resto de philos
*/