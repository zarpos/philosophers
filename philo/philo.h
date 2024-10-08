/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:09:33 by drubio-m          #+#    #+#             */
/*   Updated: 2024/08/10 18:09:43 by drubio-m         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/time.h>
# include <stdint.h>

// Defines
# define TAKE_FORK "Has taken a fork"
# define THINKING "Is thinking"
# define SLEEPING "Is sleeping"
# define EATING "Is eating"
# define DIED "Died"

// Structs
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_data
{
	int				nb_philos;
	int				finish_program;
	pthread_t		*thread_id;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				number_of_meals;
	int				ph_served;
	uint64_t		start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					meal_counter;
	int					fill;
	uint64_t			last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print;
	pthread_mutex_t		*lock;
	t_data				*data;
	int					left_fork_taken;
	int					right_fork_taken;
	int					lock_state;
}	t_philo;

// Memory
void		*routine(void *philo);
void		init_philos(t_data	*data);
void		alloc_mutex(t_data *data);
void		init_mutex(t_data *data, int i);

// Actions
void		philo_eat(t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		monitor(t_data *data);
int			killer(t_data *data, int i);
int			count_fat(t_data *data, int i);

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
void		terminate_threads(t_data *data);
void		free_misc(t_data *data);

// Lib Utils
long long	ft_atoi(const char *str);

#endif
