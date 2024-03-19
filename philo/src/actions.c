/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:45:54 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/19 11:20:22 by namoisan         ###   ########.fr       */
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

void *actions(void *struc)
{
	t_philo *philo;

	philo = (t_philo *)struc;
}