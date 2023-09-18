/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/18 19:30:31 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_data	*data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philos[i].id = i + 1;
		philos[i].meal_counter = 0;
		philos[i].status = THINKING;
		philos[i].last_meal = 0;
		philos[i].left_fork = NULL;
		philos[i].right_fork = NULL;
		philos[i].print = NULL;
		philos[i].lock = NULL;
		philos[i].data = data;
		i++;
	}
	i = 0;
	while (i )
}
