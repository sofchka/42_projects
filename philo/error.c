/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:53:38 by szakarya          #+#    #+#             */
/*   Updated: 2025/07/30 19:53:52 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	res;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9' || str[i] == '-')
			return (-1);
	}
	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res <= INT_MIN || res > INT_MAX)
		return (-1);
	return (res);
}

int	args(int ac, char **av, t_state *s)
{
	if (ac < 5 || ac > 6)
		return (ft_error("Error\n🔴 Input 4 or 5 arguments"));
	s->n = ft_atoi(av[1]);
	if (s->n < 1 || s->n > 200)
		return (ft_error("Error\n🔴 Invalid number of philosophers"));
	s->tdie = ft_atoi(av[2]);
	if (s->tdie <= 0)
		return (ft_error("Error\n🔴 Invalid time to die"));
	s->teat = ft_atoi(av[3]);
	if (s->teat <= 0)
		return (ft_error("Error\n🔴 Invalid time to eat"));
	s->tsleep = ft_atoi(av[4]);
	if (s->tsleep <= 0)
		return (ft_error("Error\n🔴 Invalid time to sleep"));
	if (ac == 6)
	{
		s->to_eat = ft_atoi(av[5]);
		if (s->to_eat <= 0)
			return (ft_error("Error\n🔴 Invalid number of times to eat"));
	}
	else
		s->to_eat = -1;
	s->someone_died = 0;
	s->start_time = 0;
	return (0);
}
