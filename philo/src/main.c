/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:22:08 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/08 14:38:15 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// faire attention avec mutex de pas deverrouiller par un autre thread que 
// celui qui l'a verouiller
// pour destroy un mutex il faut que celui soit de base deverrouiller

// initialiser

// creation de la routine en creeant un observateur en plus qui gerera tout
// (une boucle qui s'arrete quand un philo meurt)
// quand il pense juste msg "x pense", quand il dort faire usleep pdt la 
// durée donné en argument + msg "x dort", quand il mange il doit verrouiller
// les fourchettes, imprimer le msg "x mange" et mange pdt la durée donné 
// en argument (usleep) et apres il deverouille fourchette.

int	main(int argc, char **argv)
{
	t_data data;

	memset(&data, 0, sizeof(t_data));
	if (parsing(&data, argv, argc) == SUCCESS)
	{
		
	}
	else
		return (FAIL);
}