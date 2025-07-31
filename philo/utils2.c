/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:54:51 by szakarya          #+#    #+#             */
/*   Updated: 2025/07/30 19:54:53 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("%lld %d %s\n", get_time() - phi->state->start_time,
		phi->id + 1, s);
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

int	start(t_state *state, t_philo **philo, int i)
{
	int		j;
	pthread_t	death;

	if (pthread_create(&death, NULL, monitor, philo))
		return (1);
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
