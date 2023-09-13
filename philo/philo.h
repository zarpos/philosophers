/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:09:33 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/13 17:21:41 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

// Structs
typedef struct s_data
{
	int				number_of_philosophers;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		number_of_meals;
}	t_data;

typedef struct s_philo
{
	
}	t_philo;

// Philo

// Parse
void		ft_parse_arguments(int argc, char *argv[], t_data *data);
void		ft_check_valid_args(int argc, char *argv[]);
void		ft_fits_in_int(char *argv[]);
void		ft_args_to_params(char *argv[], t_data *data);

// Utils
void		ft_error(char *str);

// Lib Utils
long long	ft_atoi(const char *str);

#endif