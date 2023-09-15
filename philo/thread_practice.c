/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/15 16:15:45 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	int k  = 0;

void *routine()
{
	k += 1;
	return NULL;
}

void	ft_example(void)
{
	int i = 0;
	pthread_t	th[10];
	while (i++ < 10)
	{
		pthread_create(th + i, NULL, &routine, NULL);
		printf("Philo number :%d Has been created\n", i);
	}
	i = 0;
	while (i++ < 10)
	{
		pthread_join(th[i], NULL);
		printf("Philo number :%d Has been joined\n", i);
	}
	printf("%d", k);
}
