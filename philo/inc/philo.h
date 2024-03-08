/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:56:24 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/08 13:55:36 by namoisan         ###   ########.fr       */
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

typedef struct s_philo
{
	
}	t_philo;

typedef struct s_data
{
	t_philo	philo;
	int		dead_flag;
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_must_eat;
}	t_data;

int	parsing(t_data *data, char **argv, int argc);
void	error_msg(char *error);

//utils
int	ft_atoi(const char *str);

#endif