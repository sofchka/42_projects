#include "philo.h"

t_philo	**err(char *str, t_philo **philo, t_state *s)
{
	if (philo)
		free(philo);
	if (s->fork)
		free(s->fork);
	ft_error(str);
	return (NULL);
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000LL) + (t.tv_usec / 1000));
}

static int	init_philo(t_philo **p, int i, t_state *s)
{
	p[i] = (t_philo *)malloc(sizeof(t_philo));
	if (!p[i] || pthread_mutex_init(&p[i]->last_mutex, NULL) != 0)
	{
		while (--i >= 0)
			free(p[i]);
		i = -1;
		while (++i < s->n)
			pthread_mutex_destroy(&s->fork[i]);
		pthread_mutex_destroy(&s->print);
		free(p);
		free(s->fork);
		return (0);
	}
	p[i]->id = i;
	p[i]->eaten = 0;
	p[i]->last = s->start_time;
	p[i]->left_fork = i;
	p[i]->right_fork = (i + 1) % s->n;
	p[i]->state = s;
	return (1);
}

t_philo	**create(t_state *s, int i, t_philo **philo)
{
	philo = (t_philo **)malloc(sizeof(t_philo *) * (s->n + 1));
	s->fork = malloc(sizeof(pthread_mutex_t) * s->n);
	if (!philo || !(s->fork))
		return (err("Error\nMemory allocation failed", philo, s));
	if (pthread_mutex_init(&s->print, NULL) != 0)
		return (err("Error\nMutex init failed", philo, s));
	while (++i < s->n)
	{
		if (pthread_mutex_init(&s->fork[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&s->fork[i]);
			pthread_mutex_destroy(&s->print);
			return (err("Error\nMutex init failed", philo, s));
		}
	}
	i = -1;
	while (++i < s->n)
	{
		if (!init_philo(philo, i, s))
			return (NULL);
	}
	philo[s->n] = NULL;
	return (philo);
}
