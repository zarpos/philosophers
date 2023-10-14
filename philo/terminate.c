/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:57:58 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/14 21:16:56 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
//		pthread_mutex_unlock(data->philo[i].lock);
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
