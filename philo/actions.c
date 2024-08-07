/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:57:08 by drubio-m          #+#    #+#             */
/*   Updated: 2024/08/07 12:56:09 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, TAKE_FORK);
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, TAKE_FORK);
}

void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_action(philo, SLEEPING);
	philo_usleep(philo->data->time_to_sleep);
}

// We need to lock and unlock the print mutex
// to avoid data races when printing
void	philo_eat(t_philo *philo)
{
	while (philo->data->finish_program == 0)
	{
		pthread_mutex_unlock(philo->print);
		take_forks(philo);
		pthread_mutex_lock(philo->lock);
		philo->last_meal = set_time() - philo->data->start_time;
		if (philo->data->number_of_meals != -1)
			philo->meal_counter++;
		print_action(philo, EATING);
		pthread_mutex_unlock(philo->lock);
		philo_usleep(philo->data->time_to_eat);
		drop_forks(philo);
		print_action(philo, THINKING);
		pthread_mutex_lock(philo->print);
	}
}

