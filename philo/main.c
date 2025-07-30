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
		if (start(&state, phi))
		{
			ft_free(&state, phi);
			return (1);
		}
		ft_free(&state, phi);
	}
	return (0);
}
