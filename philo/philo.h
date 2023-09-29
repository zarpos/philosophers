/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:09:33 by drubio-m          #+#    #+#             */
/*   Updated: 2023/09/29 14:53:39 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Includes
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/_types.h>
# include <sys/time.h>

// Defines
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4

// Structs
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_data
{
	int				number_of_philosophers;
	pthread_t		thread_id;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		number_of_meals;
	uint64_t		start_time;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					meal_counter;
	int					status;
	uint64_t			last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print;
	pthread_mutex_t		*lock;
	t_data				*data;
}	t_philo;

// Philo
void		*routine(void *philo);
void		init_philos(t_data	*data);
void		alloc_mutex(t_philo *philo, t_data *data);
void		init_mutex(t_philo *philo);


// Parse
void		ft_parse_arguments(int argc, char *argv[], t_data *data);
void		ft_check_valid_args(int argc, char *argv[]);
void		ft_fits_in_int(char *argv[]);
void		ft_args_to_params(char *argv[], t_data *data);


// Utils
void		ft_error(char *str);
u_int64_t	set_time(void);
int			philo_usleep(useconds_t limit);
void		print_action(t_philo *philo, char *action);


// Lib Utils
long long	ft_atoi(const char *str);

#endif
