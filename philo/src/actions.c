/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:45:54 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/28 10:05:39 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// faire attention avec mutex de pas deverrouiller par un autre thread que 
// celui qui l'a verouiller
// pour destroy un mutex il faut que celui soit de base deverrouiller

// creation de la routine
// (une boucle qui s'arrete quand un philo meurt)
// quand il pense juste msg "x pense", quand il dort faire usleep pdt la 
// durée donné en argument + msg "x dort", quand il mange il doit verrouiller
// les fourchettes, imprimer le msg "x mange" et mange pdt la durée donné 
// en argument (usleep) et apres il deverouille fourchette.


int	eating(t_philo *philo)
{
	long long int	eat_t;

	eat_t = get_time() + philo->data->time_to_eat;
	print_action(philo, EAT);
	philo->need_eat = get_time() + philo->data->time_to_die;
	while (get_time() < eat_t)
	{
		if (philo->need_eat < get_time())
		{
			kill_philo(philo);
			return (FAIL);
		}
		usleep(100);
	}
	pthread_mutex_unlock(&philo->r_fork->fork);
	pthread_mutex_unlock(&philo->l_fork.fork);
	pthread_mutex_lock(&philo->data->fork_mutex);
	philo->r_fork->is_lock = 0;
	philo->l_fork.is_lock = 0;
	pthread_mutex_unlock(&philo->data->fork_mutex);
	return (SUCCESS);
}

//tant que le philo actuelle ne peut pas lock les 2 forks il reste dans la
//boucle
int	thinking(t_philo *philo)
{
	print_action(philo, THINK);
	usleep(100);
	while (fork_is_lock(philo) == FALSE)
	{
		if (philo->need_eat < get_time())
		{
			kill_philo(philo);
			return (FAIL);
		}
		usleep(100);
	}
	pthread_mutex_lock(&philo->r_fork->fork);
	if (print_action(philo, R_FORK) != SUCCESS)
		return (FAIL);
	pthread_mutex_lock(&philo->l_fork.fork);
	if (print_action(philo, L_FORK) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

//stocker dans une variable ton temps de sleep + get time afin de savoir quand
//sortir de la boucle. Verifier si ton need_eat(lasteat) n'est pas encore arriver
//sinon mort. Fonctionnement pas mal pareil pour eat
int	sleeping(t_philo *philo)
{
	long long int	sleep_t;
	
	sleep_t = get_time() + philo->data->time_to_sleep;
	if (print_action(philo, SLEEP) != SUCCESS)
		return (FAIL);
	while (get_time() < sleep_t)
	{
		if (philo->need_eat < get_time())
		{
			kill_philo(philo);
			return (FAIL);
		}
		usleep(100);
	}
	return (SUCCESS);
}

// usleep 1 philo sur 2 pour pas les faire demarrer en même temps 
// tant que mes philo sont en vie :
// think, si pas mort -> eat, si nombre de repas max atteint on return null pour
// finir le thread actuel, si pas mort -> sleep et voir pour remettre un usleep
// dans la boucle
void	*actions(void *struc)
{
	t_philo *philo;

	philo = (t_philo *)struc;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat);
	while(ph_is_alive(philo) == TRUE)
	{
		if (thinking(philo) != SUCCESS)
			break;
		if (eating(philo) != SUCCESS)
			break;
		if (sleeping(philo) != SUCCESS)
			break;
	}
	return (NULL);
}