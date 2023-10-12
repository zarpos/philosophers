/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:57:58 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/12 16:45:38 by drubio-m         ###   ########.fr       */
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

	i = 0;
	while (i < data->nb_philos)
	{
	//	printf("No he hecho todavía el unlock de los lock\n");
		pthread_mutex_unlock(data->philo[i].lock);
	//	printf("Ahora si he hecho todavía el unlock de los lock\n");
	//	printf("Estoy esperando para hacer el join\n");
	//	printf("valor del thread id antes del join %p\n", data->thread_id[i]);
		pthread_join(data->thread_id[i], NULL);
	//	printf("valor del thread id después del join %p\n", data->thread_id[i]);
		i++;
	}

/* 	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&(data->lock[i]));
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(data->print[i]));
		i++;
	} */
}
