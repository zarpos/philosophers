/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:50:26 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/26 18:21:50 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


u_int64_t	set_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		ft_error("Failed to get time of the day");
//	printf("Este es el tiempo en microsegundos %llu\n", time.tv_sec * (u_int64_t)1000 + time.tv_usec / 1000);
	return (time.tv_sec * (u_int64_t)1000 + time.tv_usec / 1000);
}

int	philo_usleep(useconds_t limit)
{
	uint64_t	begin;

	begin = set_time();
	while ((set_time() - begin) < limit)
		usleep(limit / 10);
	return (0);
}
