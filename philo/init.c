/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2024/08/11 21:51:56 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Routine for the philos
// They lock and unlock the print mutex to avoid printing at the same time
void	*routine(void *philo_no_casted)
{
	t_philo	*philo;

	philo = philo_no_casted;
	if (philo->id % 2 == 0)
		philo_usleep(100);
	pthread_mutex_lock(philo->print);
	philo_eat(philo);
	pthread_mutex_unlock(philo->print);
	return (NULL);
}

void	alloc_mutex(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philo)
		ft_error("Failed to alloc memory for philosophers");
	data->thread_id = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->thread_id)
		ft_error("Failed to alloc memory for thread IDs");
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		ft_error("Failed to alloc memory for forks");
	data->lock = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->lock)
		ft_error("Failed to alloc memory for locks");
	data->print = malloc(sizeof(pthread_mutex_t));
	if (!data->print)
		ft_error("Failed to alloc memory for print mutex");
	data->start_time = set_time();
	data->finish_program = 0;
	data->ph_served = 0;
	data->philo->left_fork_taken = 0;
	data->philo->right_fork_taken = 0;
}

void	init_mutex(t_data *data, int i)
{
	if (pthread_mutex_init(&(data->lock[i]), NULL))
		ft_error("Failed to initialize lock mutex");
	data->philo[i].lock = &(data->lock[i]);
	if (pthread_mutex_init(data->print, NULL) && i == 0)
		ft_error("Failed to initialize print mutex");
	data->philo[i].print = data->print;
	if (pthread_mutex_init(&(data->forks[i]), NULL))
		ft_error("Failed to initialize fork mutex");
	data->philo[i].right_fork = &(data->forks[i]);
	data->philo[i].left_fork = &(data->forks[(i + 1) % data->nb_philos]);
}

// In this function we will initiate all the variables of the philos
// And also create all the threads for the different philos
void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		init_mutex(data, i);
		data->philo[i].id = i + 1;
		data->philo[i].meal_counter = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].fill = 0;
		data->philo[i].data = data;
	}
	i = -1;
	while (++i < data->nb_philos)
		pthread_create(&(data->thread_id[i]), NULL, routine, &(data->philo[i]));
}
