#include "philo.h"

void	status(t_philo *phi, char *s)
{
	if (phi->state->someone_died == 1)
		return ;
	pthread_mutex_lock(phi->print);
	printf("%lld %d %s\n", get_time() - phi->state->start_time, phi->id + 1, s);
	pthread_mutex_unlock(phi->print);
}

void	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (!philo->state->someone_died)
	{
		philo->state->someone_died = 1;
		printf("%lld %d died\n", get_time() - philo->state->start_time,
			philo->id + 1);
	}
	pthread_mutex_unlock(philo->print);
}

void	sleeping(long long time, t_state *state)
{
	long long	start;

	start = get_time();
	while (!state->someone_died && get_time() - start < time)
		usleep(100);
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

	if (philo->state->someone_died)
		return (1);
	first = smaller(philo->left_fork, philo->right_fork, &second);
	pthread_mutex_lock(&philo->state->fork[first]);
	status(philo, "has taken a fork");
	if (philo->state->n == 1)
	{
		pthread_mutex_unlock(&philo->state->fork[first]);
		return (1);
	}
	pthread_mutex_lock(&philo->state->fork[second]);
	status(philo, "has taken a fork");
	status(philo, "is eating");
	philo->eaten++;
	sleeping(philo->state->teat, philo->state);
	philo->last = get_time();
	pthread_mutex_unlock(&philo->state->fork[second]);
	pthread_mutex_unlock(&philo->state->fork[first]);
	return (0);
}
