/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:22:08 by namoisan          #+#    #+#             */
/*   Updated: 2024/04/05 11:49:41 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	memset(&data, 0, sizeof(t_data));
	if (parsing(&data, argv, argc) == SUCCESS)
	{
		if (init(&data) == FAIL)
			return (FAIL);
		i = 0;
		while (i < data.nb_philo)
		{
			if (pthread_join(data.philo[i].thread, NULL) != 0)
				break ;
			i++;
		}
		ft_exit(&data);
	}
	else
		return (FAIL);
	return (SUCCESS);
}
