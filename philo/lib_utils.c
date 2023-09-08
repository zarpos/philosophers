/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:04:18 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/08 17:05:28 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	long			i;
	int				sign;
	unsigned long	sol;

	i = 0;
	sign = 1;
	sol = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sol = (sol * 10) + (str[i] - '0');
		i++;
	}
	if (sol > 2147483647 && sign == 1)
		ft_error();
	if (sol > 2147483648 && sign == -1)
		ft_error();
	return (sol * sign);
}

void	ft_error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}