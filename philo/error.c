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

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * j);
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
