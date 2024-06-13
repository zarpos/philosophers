/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:50:26 by drubio-m          #+#    #+#             */
/*   Updated: 2024/06/13 11:34:55 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// In this function we are going to get the time of the day and make a counter
u_int64_t	set_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		ft_error("Failed to get time of the day");
	return (time.tv_sec * (u_int64_t)1000 + (time.tv_usec / 1000));
}

// We check if the time has passed the limit
// We are creating a loop that will run dividing the limit by 10
// The division is made for the usleep function to be more precise
// And less CPU intensive
int	philo_usleep(useconds_t limit)
{
	uint64_t	begin;

	begin = set_time();
	while ((set_time() - begin) < limit)
		usleep(limit / 10);
	return (0);
}

// This function will print the philo action, protected by a mutex
void	print_action(t_philo *philo, char *action)
{
	int			id;
	uint64_t	time;

	pthread_mutex_lock(philo->print);
	id = philo->id;
	time = philo->data->start_time;
	if (philo->data->finish_program == 0)
		printf("%lums %d %s\n", set_time() - time, id, action);
	pthread_mutex_unlock(philo->print);
}
