#include "philo.h"

void	end(char *str, t_philo	**philos)
{
	pthread_mutex_lock(&philos[0]->state->print);
	printf("%s", str);
	pthread_mutex_unlock(&philos[0]->state->print);
}

void	*monitor(void *arg)
{
	t_philo		**p;
	int			i;
	int			all_ate;
	long long	time_since_last;

	p = (t_philo **)arg;
	usleep(5000);
	while (1)
	{
		pthread_mutex_lock(&p[0]->state->died_mutex);
		if (p[0]->state->someone_died)
		{
			pthread_mutex_unlock(&p[0]->state->died_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&p[0]->state->died_mutex);
		all_ate = 0;
		i = -1;
		while (++i < p[0]->state->n)
		{
			pthread_mutex_lock(&p[i]->last_mutex);
			time_since_last = get_time() - p[i]->last;
			if (time_since_last >= p[i]->state->tdie)
			{
				pthread_mutex_unlock(&p[i]->last_mutex);
				dead(p[i]);
				return (NULL);
			}
			if (p[i]->state->to_eat != -1 && p[i]->eaten >= p[i]->state->to_eat)
				all_ate++;
			pthread_mutex_unlock(&p[i]->last_mutex);
		}
		if (p[0]->state->to_eat != -1 && all_ate == p[0]->state->n)
		{
			end("✅ All philos have eaten enough: DONE\n", p);
			return (NULL);
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
	pthread_mutex_lock(&philo->last_mutex);
	philo->last = get_time();
	pthread_mutex_unlock(&philo->last_mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->state->died_mutex);
		if (philo->state->someone_died)
		{
			pthread_mutex_unlock(&philo->state->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->state->died_mutex);
		if (eating(philo))
			break ;
		pthread_mutex_lock(&philo->last_mutex);
		if (philo->state->to_eat != -1 && philo->eaten >= philo->state->to_eat)
		{
			pthread_mutex_unlock(&philo->last_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->last_mutex);
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
			pthread_mutex_lock(&state->died_mutex);
            state->someone_died = 1;
            pthread_mutex_unlock(&state->died_mutex);
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
