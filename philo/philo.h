/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:09:33 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/07 18:15:35 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// Structs
	
// Philo

// Parse
int	ft_check_valid_args(int argc, char *argv[]);
void ft_args_to_params(char *argv[]);



// Utils
void	ft_error(void);

// Lib Utils
long	ft_atoi(const char *str);

#endif
