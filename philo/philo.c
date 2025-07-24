#include "philo.h"

void	end(char *str, t_philo	**philos)
{
	pthread_mutex_lock(&philos[0]->state->print);
	printf("%s", str);
	pthread_mutex_unlock(&philos[0]->state->print);
}

void	*monitor(void *arg)
{
	t_philo	**p;
	int		i;
	int		all_ate;

	p = (t_philo **)arg;
	usleep(5000);
	while (1)
	{
		all_ate = 0;
		i = -1;
		while (++i < p[0]->state->n)
		{
			if (get_time() - p[i]->last >= p[i]->state->tdie)
			{
				dead(p[i]);
				return (end("🔴 ENDED WITH DEATH :(\n", p), NULL);
			}
			if (p[i]->state->to_eat != -1 && p[i]->eaten >= p[i]->state->to_eat)
				all_ate++;
			if (p[0]->state->to_eat != -1 && all_ate == p[0]->state->n)
				return (end("✅ All philos have eaten enough: DONE\n", p), NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
	{
		if (philo->state->n >= 5)
			usleep(20000);
		else
			usleep(1000);
	}
	philo->last = get_time();
	while (!philo->state->someone_died)
	{
		if (eating(philo))
			break ;
		if (philo->state->to_eat != -1
			&& philo->eaten >= philo->state->to_eat)
			break ;
		status(philo, "is sleeping");
		sleeping(philo->state->tsleep, philo->state);
		status(philo, "is thinking");
	}
	return (NULL);
}

int	start(t_state *state, t_philo **philo)
{
	int			i;
	int			j;
	pthread_t	death;

	if (pthread_create(&death, NULL, monitor, philo))
		return (1);
	i = -1;
	while (++i < state->n)
	{
		if (pthread_create(&philo[i]->thread, NULL, start_routine, philo[i]))
		{
			state->someone_died = 1;
			pthread_join(death, NULL);
			j = -1;
			while (++j < i)
				pthread_join(philo[j]->thread, NULL);
			return (1);
		}
	}
	pthread_join(death, NULL);
	i = -1;
	while (++i < state->n)
		pthread_join(philo[i]->thread, NULL);
	return (0);
}
