/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:02:38 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/19 10:28:37 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// parsing validation: 
// 1 verifier si pas plus de 5 arguments (5eme optionnel)
// (si 4 j'envoie comme si mon 5eme arg etait à -1)
// 2 verifier si c'est bien que des nombres > 0 sauf nb de repas et pas + 
// que 200 philo

int	is_valid_number(char **argv)
{
	int i;
	int j;
	
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	parsing(t_data *data, char **argv, int argc)
{
	if (argc == 5 || argc == 6)
	{
		if (is_valid_number(argv) == TRUE)
		{
			if (ft_atoi(argv[1]) < 1 && ft_atoi(argv[1]) > 200)
				error_msg("Number of philosophers must be between 1 and 200");
			data->nb_philo = ft_atoi(argv[1]);
			data->time_to_die = ft_atoi(argv[2]);
			data->time_to_eat = ft_atoi(argv[3]);
			data->time_to_sleep = ft_atoi(argv[4]);
			if (argc == 6)
				data->nb_must_eat = ft_atoi(argv[5]);
			else
				data->nb_must_eat = -1;
		}
		else
			error_msg("Arguments must only be digit (>= 0)");
	}
	else
		error_msg("Invalid number of arguments");
	return (SUCCESS);
}
