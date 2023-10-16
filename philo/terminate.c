/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:57:58 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/16 02:27:13 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_philos)
		{
			pthread_mutex_lock(data->philo[i].lock);
			if (killer(data, i))
				return ;
			pthread_mutex_unlock(data->philo[i].lock);
		}
	}
}

int	killer(t_data *data, int i)
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
		pthread_mutex_unlock(data->philo[i].left_fork);
		return (1);
	}
	return (0);
}

void	free_misc(t_data *data)
{
	free(data->philo);
	free(data->thread_id);
	free(data->lock);
	free(data->forks);
	free(data->print);
}

void	terminate_threads(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->nb_philos)
	{
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
