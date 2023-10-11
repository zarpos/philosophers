/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:57:08 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/11 23:51:30 by drubio-m         ###   ########.fr       */
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
	while (!philo->finish_program)
	{
		pthread_mutex_unlock(philo->print);
		take_forks(philo);
		pthread_mutex_lock(philo->lock);
		print_action(philo, EATING);
		philo->last_meal = set_time() - philo->data->start_time;
		pthread_mutex_unlock(philo->lock);
		philo_usleep(philo->data->time_to_eat);
		drop_forks(philo);
		print_action(philo, THINKING);
		pthread_mutex_lock(philo->print);
	}
}