/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:07:04 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/10 19:25:24 by drubio-m         ###   ########.fr       */
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
	printf("\n Estoy antes del if");
	printf("%s%d", "\n", argc);
	if (argc < 5 || argc > 6)
		ft_error();
	printf("\n Estoy después del if");
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
	printf("\n argumento super válido");
	ft_args_to_params(argv, data);
	return (0);
}

void	ft_args_to_params(char *argv[], t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	printf("\nArgumento 1 ok");
	data->time_to_die = ft_atoi(argv[2]);
	printf("\nArgumento 2 ok");
	data->time_to_eat = ft_atoi(argv[3]);
	printf("\nArgumento 3 ok");
	data->time_to_sleep = ft_atoi(argv[4]);
	printf("\nArgumento 4 ok");
	if (argv[5])
	{
		printf("\n Dentro del if del Argumento 5 ok");
		data->number_of_meals = ft_atoi(argv[5]);
		printf("\nArgumento 5 ok");
	}
}

