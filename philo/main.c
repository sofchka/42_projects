/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:54:15 by szakarya          #+#    #+#             */
/*   Updated: 2025/07/30 19:54:17 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_state	*state, t_philo	**phi)
{
	int	i;

	if (phi)
	{
		i = -1;
		while (++i < state->n)
		{
			if (phi[i])
			{
				pthread_mutex_destroy(&phi[i]->last_mutex);
				free(phi[i]);
			}
		}
		free(phi);
	}
	if (state->fork)
	{
		i = -1;
		while (++i < state->n)
			pthread_mutex_destroy(&state->fork[i]);
		free(state->fork);
	}
	pthread_mutex_destroy(&state->print);
	pthread_mutex_destroy(&state->died_mutex);
}

int	main(int ac, char **av)
{
	t_state	state;
	t_philo	**phi;

	if (args(ac, av, &state) == 0)
	{
		state.start_time = get_time();
		phi = create(&state, -1, NULL);
		if (!phi)
			return (1);
		if (state.n == 1)
		{
			printf("0 1 has taken a fork\n");
			usleep((state.tdie + 1) * 1000);
			printf("%d 1 died\n", state.tdie + 1);
			ft_free(&state, phi);
			return (1);
		}
		if (start(&state, phi, -1))
		{
			ft_free(&state, phi);
			return (1);
		}
		ft_free(&state, phi);
	}
	return (0);
}
