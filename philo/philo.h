#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;//indexx of philos
	int				eaten;//for each philo
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	last_mutex;
	pthread_mutex_t	check;
	long long		last;//for each philo
	struct s_state	*state;
	pthread_t		thread;//routine
}	t_philo;

typedef struct s_state
{
	int				someone_died;
	int				n;
	int				to_eat;
	int				tdie;
	int				teat;
	int				tsleep;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_state;

int			ft_error(char *str);
int			ft_atoi(const char *str);

t_philo		**create(t_state *s, int i, t_philo **philo);
int			start(t_state *state, t_philo **philo);
int			args(int ac, char **av, struct s_state *s);

void		status(t_philo *philo, char *str);

long long	get_time(void);
int			eating(t_philo *philo);
void		dead(t_philo *philo);
void		sleeping(long long time, t_state *state);

#endif
