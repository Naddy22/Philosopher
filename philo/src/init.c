/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:34:45 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/15 15:44:45 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	init_philo(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].died = 0;
		data->philo[i].r_fork = NULL;
		data->philo[i].l_fork.is_lock = 0;
		data->philo[i].data = data;
		data->philo[i].eat_count = 0;
		pthread_mutex_init(&data->philo[i].l_fork.fork, NULL);
		if (i == data->nb_philo - 1)
			data->philo[i].r_fork = &data->philo[0].l_fork;
		else
			data->philo[i].r_fork = &data->philo[i + 1].l_fork;
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if(pthread_create(&data->philo[i].thread, NULL, &actions, \
		&data->philo[i]) != 0)
			return (FAIL);
	}
	return (SUCCESS);
}

int	init(t_data *data)
{
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->fork_mutex, NULL);
	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (data->philo == NULL)
	{
		error_msg("Malloc failed");
		return (FAIL);
	}
	if (init_philo(data) == FAIL)
	{
		ft_exit(data);
		error_msg("Init philo failed");
		return (FAIL);
	}
	return (SUCCESS);
}
