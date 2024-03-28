/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:19:51 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/28 09:19:04 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	kill_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->dead_flag != 1)
	{
		philo->died = 1;
		philo->data->dead_flag = 1;
		pthread_mutex_lock(&philo->data->death_mutex);
		print_action(philo, DIED);
		return ;
	}
	pthread_mutex_lock(&philo->data->death_mutex);
}

int	ph_is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if(philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (TRUE);
}

int fork_is_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_mutex);
	if (&philo->l_fork.fork == &philo->r_fork->fork)
	{
		pthread_mutex_unlock(&philo->data->fork_mutex);
		return (FALSE);
	}
	else if (philo->l_fork.is_lock == 0 && philo->r_fork->is_lock == 0)
	{
		philo->l_fork.is_lock = 1;
		philo->r_fork->is_lock = 1;
		pthread_mutex_unlock(&philo->data->fork_mutex);
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->fork_mutex);
		return (FALSE);
	}
}

int	print_action(t_philo *philo, const char *msg)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (ph_is_alive(philo) == TRUE)
		printf("%lld %d %s\n", get_time(), philo->id, msg);
	else
	{
		return (FAIL);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (SUCCESS);
}