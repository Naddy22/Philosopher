/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:07:07 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/15 14:22:51 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_msg(char *error)
{
	printf("Error : %s\n", error);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
		pthread_mutex_destroy(&data->philo[i].l_fork.fork);
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->fork_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}