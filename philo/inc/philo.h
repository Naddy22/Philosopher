/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:56:24 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/15 15:48:41 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1

typedef struct s_fork
{
	int				is_lock;
	pthread_mutex_t	fork;
}					t_fork;

typedef struct s_philo
{
	int			id;
	int			died;
	int			eat_count;
	int			last_eat;
	pthread_t	thread;
	t_fork		*r_fork;
	t_fork		l_fork;
	t_data		*data;
}				t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				dead_flag;
	int				start_time;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	pthread_mutex_t print_mutex;
	pthread_mutex_t fork_mutex;
	pthread_mutex_t death_mutex;
}					t_data;

int	parsing(t_data *data, char **argv, int argc);

void	error_msg(char *error);
void	ft_exit(t_data *data);

int	init(t_data *data);

void *actions(void *struc);

//utils
int	ft_atoi(const char *str);

#endif