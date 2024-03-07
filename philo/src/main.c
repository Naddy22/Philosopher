/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:22:08 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/07 15:55:20 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// faire attention avec mutex de pas deverrouiller par un autre thread que 
// celui qui l'a verouiller
// pour destroy un mutex il faut que celui soit de base deverrouiller

// parsing validation: 
// 1 verifier si pas plus de 5 arguments (5eme optionnel)
// (si 4 j'envoie comme si mon 5eme arg etait à 0)
// 2 verifier si c'est bien que des nombres > 0 sauf nb de repas et pas + 
// que 200 philo

// construire les structures

// initialiser

// creation de la routine en creeant un observateur en plus qui gerera tout
// (une boucle qui s'arrete quand un philo meurt)
// quand il pense juste msg "x pense", quand il dort faire usleep pdt la 
// durée donné en argument + msg "x dort", quand il mange il doit verrouiller
// les fourchettes, imprimer le msg "x mange" et mange pdt la durée donné 
// en argument (usleep) et apres il deverouille fourchette.

