/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:07:04 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/07 16:58:02 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_valid_args(int argc, char *argv[])
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
	return (0);
}

void	ft_args_to_params(char *argv[])
{
		
}

void	ft_error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}
