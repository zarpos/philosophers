/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:22:09 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/16 19:33:58 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	int k  = 0;
	int primes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void *routine(void *arg)
{
	int index = *(int *)arg;
	printf("Me ha tocado el número : %d\n", primes[index]);
	k += 1;
	return NULL;
}

void	ft_example(void)
{
	int i = 0;
	pthread_t	th[10];
	while (i++ < 10)
	{
		pthread_create(th + i, NULL, &routine, &i);
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
