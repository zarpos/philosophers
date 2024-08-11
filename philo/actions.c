/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:57:08 by drubio-m          #+#    #+#             */
/*   Updated: 2024/08/11 21:47:33 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
	{
		print_action(philo, THINKING);
		return ;
	}
	if (philo->right_fork < philo->left_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		philo->right_fork_taken = 1;
		pthread_mutex_lock(philo->left_fork);
		philo->left_fork_taken = 1;
		print_action(philo, TAKE_FORK);
		print_action(philo, TAKE_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		philo->left_fork_taken = 1;
		print_action(philo, TAKE_FORK);
		pthread_mutex_lock(philo->right_fork);
		philo->right_fork_taken = 1;
		print_action(philo, TAKE_FORK);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	philo->right_fork_taken = 0;
	pthread_mutex_unlock(philo->left_fork);
	philo->left_fork_taken = 0;
	print_action(philo, SLEEPING);
	philo_usleep(philo->data->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
	{
		pthread_mutex_unlock(philo->print);
		print_action(philo, THINKING);
		pthread_mutex_lock(philo->print);
		return ;
	}
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
