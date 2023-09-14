/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/14 12:40:35 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	int i = 1;

void *routine()
{

	printf("hola que tal soy el philo: %d\n", i++);
	return NULL;
}

void	ft_example(void)
{
	pthread_t	th[1000000];
	int i = 0;
	while (i++ < 1000000)
	{
		pthread_create(th + i, NULL, &routine, NULL);
		pthread_join(th[i], NULL);
	}
}
