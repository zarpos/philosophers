/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:07:04 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/28 10:20:19 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This function calls the functions to parse the arguments
void	ft_parse_arguments(int argc, char *argv[], t_data *data)
{
	ft_check_valid_args(argc, argv);
	ft_fits_in_int(argv);
	ft_args_to_params(argv, data);
}

// This function checks if there are the right number of arguments
// and if they are numbers
void	ft_check_valid_args(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 5 || argc > 6)
		ft_error("Invalid number or arguments");
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '\0')
				ft_error("Argument is not a number");
			j++;
		}
		i++;
	}
}

// This function checks if the arguments fit in an int
void	ft_fits_in_int(char *argv[])
{
	int	i;

	i = 0;
	while (argv[++i])
		ft_atoi(argv[i]);
}

// This function converts the arguments to the data struct
void	ft_args_to_params(char *argv[], t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->number_of_meals = ft_atoi(argv[5]);
	data->start_time = set_time();
}
