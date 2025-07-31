/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:54:59 by szakarya          #+#    #+#             */
/*   Updated: 2025/07/30 19:55:03 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	small(int a, int b, int *c)
{
	if (a < b)
	{
		*c = b;
		return (a);
	}
	*c = a;
	return (b);
}

int	eating_2(t_philo *philo, int first, int second)
{
	status(philo, "has taken a fork");
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
	return (0);
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
	first = small(philo->left_fork, philo->right_fork, &second);
	pthread_mutex_lock(&philo->state->fork[first]);
	if (eating_2(philo, first, second) == 1)
		return (1);
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
