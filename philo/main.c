#include "philo.h"

void	ft_free(t_state	*state, t_philo	**phi)
{
	int		i;

	if (state->fork)
		free(state->fork);
	if (phi)
	{
		i = -1;
		while (++i < state->n)
		{
			pthread_mutex_destroy(&state->fork[i]);
			pthread_mutex_destroy(&phi[i]->last_mutex);
			if (phi[i])
				free(phi[i]);
		}
		pthread_mutex_destroy(&state->print);
		pthread_mutex_destroy(&state->died_mutex);
		if (phi)
			free(phi);
	}
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
