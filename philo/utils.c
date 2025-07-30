#include "philo.h"

void	status(t_philo *phi, char *s)
{
	pthread_mutex_lock(&phi->state->died_mutex);
	if (phi->state->someone_died == 1)
	{
		pthread_mutex_unlock(&phi->state->died_mutex);
		return ;
	}
	pthread_mutex_lock(&phi->state->print);
	pthread_mutex_unlock(&phi->state->died_mutex);
	printf("%lld %d %s (eaten: %d)\n", get_time() - phi->state->start_time,
		phi->id + 1, s, phi->eaten);
	pthread_mutex_unlock(&phi->state->print);
}

void	dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->died_mutex);
	philo->state->someone_died = 1;
	pthread_mutex_unlock(&philo->state->died_mutex);
	pthread_mutex_lock(&philo->state->print);
	printf("%lld %d died\n", get_time() - philo->state->start_time,
		philo->id + 1);
	pthread_mutex_unlock(&philo->state->print);
}

void	sleeping(long long time, t_state *state)
{
	long long	start;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(&state->died_mutex);
		if (state->someone_died || get_time() - start >= time)
		{
			pthread_mutex_unlock(&state->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&state->died_mutex);
		usleep(50);
	}
}

int	smaller(int a, int b, int *c)
{
	if (a < b)
	{
		*c = b;
		return (a);
	}
	*c = a;
	return (b);
}

int	eating(t_philo *philo)
{
	int	first;
	int	second;

	pthread_mutex_lock(&philo->state->died_mutex);
	if (philo->state->someone_died)
	{
		pthread_mutex_unlock(&philo->state->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->state->died_mutex);
	first = smaller(philo->left_fork, philo->right_fork, &second);
	pthread_mutex_lock(&philo->state->fork[first]);
	status(philo, "has taken a fork");
	if (philo->state->n == 1)
	{
		pthread_mutex_unlock(&philo->state->fork[first]);
		return (1);
	}
	pthread_mutex_lock(&philo->state->fork[second]);
	pthread_mutex_lock(&philo->state->died_mutex);
	if (philo->state->someone_died)
	{
		pthread_mutex_unlock(&philo->state->died_mutex);
		pthread_mutex_unlock(&philo->state->fork[second]);
		pthread_mutex_unlock(&philo->state->fork[first]);
		return (1);
	}
	pthread_mutex_unlock(&philo->state->died_mutex);
	pthread_mutex_lock(&philo->last_mutex);
	philo->last = get_time();
	philo->eaten++;
	pthread_mutex_unlock(&philo->last_mutex);
	status(philo, "has taken a fork");
	status(philo, "is eating");
	sleeping(philo->state->teat, philo->state);
	pthread_mutex_unlock(&philo->state->fork[second]);
	pthread_mutex_unlock(&philo->state->fork[first]);
	return (0);
}
