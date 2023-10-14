/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:57:08 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/14 20:53:45 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
//	pthread_mutex_lock(philo->right_fork);
	print_action(philo, TAKE_FORK);
//	pthread_mutex_lock(philo->left_fork);
	print_action(philo, TAKE_FORK);
}

void	drop_forks(t_philo *philo)
{
//	pthread_mutex_unlock(philo->right_fork);
//	pthread_mutex_unlock(philo->left_fork);
	print_action(philo, SLEEPING);
	philo_usleep(philo->data->time_to_sleep);
}

// We need to lock and unlock the print mutex 
// to avoid data races when printing
void	philo_eat(t_philo *philo)
{
//	printf("Soy el philo %d y estoy al principio de la rutina\n", philo->id);
	while (!philo->finish_program)
	{
	//	pthread_mutex_unlock(philo->print);
		take_forks(philo);
	//	pthread_mutex_lock(philo->lock);
	//	printf("Soy el philo %d y estoy a punto de comer\n", philo->id);
		print_action(philo, EATING);
	//	printf("Soy el philo %d y acabo de comer\n", philo->id);
		philo->last_meal = set_time() - philo->data->start_time;
	//	printf("Soy el philo %d y acabo de comer y mi last_meal es %llu\n", philo->id, philo->last_meal);
	//	pthread_mutex_unlock(philo->lock);
	//	printf("Soy el philo %d y estoy a punto de dormir\n", philo->id);
		philo_usleep(philo->data->time_to_eat);
	//	printf("Soy el philo %d y acabo de dormir\n", philo->id);
		drop_forks(philo);
	//	printf("Soy el philo %d y estoy a punto de pensar\n", philo->id);
		print_action(philo, THINKING);
	//	printf("Soy el philo %d y acabo de pensar\n", philo->id);
	//	pthread_mutex_lock(philo->print);
	}
}
