/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:54:24 by szakarya          #+#    #+#             */
/*   Updated: 2025/07/30 19:54:26 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(char *str, t_philo	**philos)
{
	pthread_mutex_lock(&philos[0]->state->print);
	printf("%s", str);
	pthread_mutex_unlock(&philos[0]->state->print);
}

int	monitor_2(t_philo **p, int i, int *all_ate)
{
	long long	time_since_last;

	pthread_mutex_lock(&p[i]->last_mutex);
	time_since_last = get_time() - p[i]->last;
	if ((p[i]->eaten < p[i]->state->to_eat || p[i]->state->to_eat == -1)
		&& time_since_last > p[i]->state->tdie)
	{
		pthread_mutex_unlock(&p[i]->last_mutex);
		dead(p[i]);
		return (1);
	}
	if (p[i]->state->to_eat != -1 && p[i]->eaten >= p[i]->state->to_eat)
		(*all_ate)++;
	pthread_mutex_unlock(&p[i]->last_mutex);
	return (0);
}

int	dead_case(t_philo **p)
{
	pthread_mutex_lock(&p[0]->state->died_mutex);
	if (p[0]->state->someone_died)
	{
		pthread_mutex_unlock(&p[0]->state->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&p[0]->state->died_mutex);
	return (0);
}

void	*monitor(void *arg)
{
	t_philo		**p;
	int			i;
	int			all_ate;

	p = (t_philo **)arg;
	usleep(5000);
	while (1)
	{
		if (dead_case(p) == 1)
			return (NULL);
		all_ate = 0;
		i = -1;
		while (++i < p[0]->state->n)
		{
			if (monitor_2(p, i, &all_ate) == 1)
				return (NULL);
		}
		if (p[0]->state->to_eat != -1 && all_ate == p[0]->state->n)
		{
			end("✅ All philos have eaten enough: DONE\n", p);
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep((philo->id % 2) * 10000);
	pthread_mutex_lock(&philo->last_mutex);
	philo->last = get_time();
	pthread_mutex_unlock(&philo->last_mutex);
	while (1)
	{
		if (dead_case(&philo) == 1)
			return (NULL);
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
