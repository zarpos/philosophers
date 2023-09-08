/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:34:18 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/08 17:08:44 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_data	*data;

	if (ft_check_valid_args(argc, argv, &data) == 1)
		ft_error();
	printf("\nooleeee");
	return (0);
}

/*
ARGUMENTOS
1. number_of_philosophers 
2. time_to_die 
3. time_to_eat
4. time_to_sleep
5. [number_of_times_each_philosopher_must_eat]

*/