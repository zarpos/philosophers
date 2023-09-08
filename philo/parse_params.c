/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:07:04 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/08 17:08:47 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct_data(t_philo philo)
{
	
}

int	ft_check_valid_args(int argc, char *argv[], t_data *data)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 5 || argc > 6)
		ft_error();
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '\0')
				return (1);
			j++;
		}
		i++;
	}
	//ft_args_to_params(argv, data);
	return (0);
}

void	ft_args_to_params(char *argv[], t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != '\0')
		data->number_of_meals = ft_atoi(argv[5]);
}

