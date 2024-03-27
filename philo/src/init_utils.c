/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:45:28 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/27 10:20:26 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long int	get_time(void)
{
	static struct timeval start = {-1, -1};
	struct timeval now;
	long long int result;

	result = 0;
	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	result = (now.tv_sec - start.tv_sec) * 1000;
	result = result + (now.tv_usec - start.tv_usec) / 1000;
	return (result);
}

static int	ft_atoi_part(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str == 0)
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	result = ft_atoi_part(&str[i]);
	return (result * sign);
}
