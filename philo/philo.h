/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:54:39 by szakarya          #+#    #+#             */
/*   Updated: 2025/07/30 19:54:42 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				eaten;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	last_mutex;
	long long		last;
	struct s_state	*state;
	pthread_t		thread;
}					t_philo;

typedef struct s_state
{
	int				someone_died;
	int				n;
	int				to_eat;
	int				tdie;
	int				teat;
	int				tsleep;
	long long		start_time;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_state;

int					ft_error(char *str);
long				ft_atol(const char *str);

void				*monitor(void *arg);
void				*start_routine(void *arg);
t_philo				**create(t_state *s, int i, t_philo **philo);
int					start(t_state *state, t_philo **philo, int i);
int					args(int ac, char **av, struct s_state *s);

void				status(t_philo *philo, char *str);
void				ft_free(t_state *state, t_philo **phi);
long long			get_time(void);
int					eating(t_philo *philo);
void				dead(t_philo *philo);
void				sleeping(long long time, t_state *state);

#endif
