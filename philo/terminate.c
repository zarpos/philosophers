/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:57:58 by drubio-m          #+#    #+#             */
/*   Updated: 2024/08/10 18:18:03 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// It will be adding to data->ph_served one iteration each time a philo
// reaches the minimun amount of dinners
int count_fat(t_data *data, int i)
{
	if (data->number_of_meals == data->philo[i].meal_counter && data->philo[i].fill == 0)
	{
		data->philo[i].fill = 1;
		data->ph_served++;
		if (data->ph_served == data->nb_philos)
		{
			pthread_mutex_lock(data->philo[i].print);
			data->finish_program = 1;
			pthread_mutex_unlock(data->philo[i].print);
			return (1);
		}
	}
	return (0);
}

// It's an infite loop checking if any philo has died
void monitor(t_data *data)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_philos)
		{
			pthread_mutex_lock(data->philo[i].lock);
			data->philo[i].lock_state = 1;
			if (killer(data, i) || count_fat(data, i))
				return;
			pthread_mutex_unlock(data->philo[i].lock);
			data->philo[i].lock_state = 0;
		}
	}
}


// Calculates the time to see if someone has died
int killer(t_data *data, int i)
{
	uint64_t	time;
	uint64_t	last_m;
	uint64_t	ttd;

	time = data->start_time;
	last_m = data->philo[i].last_meal;
	ttd = data->time_to_die;
	if (set_time() - time - last_m > ttd)
	{
		print_action(&(data->philo[i]), DIED);
		pthread_mutex_lock(data->print);
		data->finish_program = 1;
		pthread_mutex_unlock(data->print);
		if (data->philo[i].left_fork_taken == 1)
			pthread_mutex_unlock(data->philo[i].left_fork);
		if (data->philo[i].right_fork_taken == 1)
			pthread_mutex_unlock(data->philo[i].right_fork);
		return (1);
	}
	return (0);
}

// Liberates all the data to avoid leaks
void free_misc(t_data *data)
{
	free(data->philo);
	free(data->thread_id);
	free(data->lock);
	free(data->forks);
	free(data->print);
}

// With join we wait for the threads to end
// before ending them, we unlock the mutex
// At the end we need to destroy all the mutex
void terminate_threads(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philo[i].lock_state)
			pthread_mutex_unlock(data->philo[i].lock);
		pthread_join(data->thread_id[i], NULL);
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		pthread_mutex_destroy(&(data->lock[i]));
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(data->print[i]));
	}
}
