/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:01:56 by adelille          #+#    #+#             */
/*   Updated: 2021/11/29 18:57:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define USLEEP	300
# define OPTI	995

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"

# define EATING		0
# define SLEEPING	1
# define THINKING	2

# define START	0
# define HALF	1
# define ALL	2
# define STOP	3

typedef struct s_arg
{
	int		n_philo;
	time_t	ms_alive;
	time_t	ms_eating;
	time_t	ms_sleeping;
	int		n_eat_max;
}			t_arg;

typedef struct s_main
{
	t_arg			arg;
	struct s_philo	*philosophers;
	pthread_t		*threads;
	time_t			time;
	int				status;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	print_mutex;
	bool			finish_eat;
}					t_main;

// might delete action
typedef struct s_philo
{
	t_arg			arg;
	int				id;
	int				action;
	int				eat_count;
	time_t			last_meal;
	pthread_mutex_t	fork_mutex;
	t_main			*main;
}					t_p;

bool	ft_arg(int ac, char **av, t_arg *arg);
bool	ft_init_main(t_main *m);

void	*ft_launcher(t_p *p);

bool	ft_lock_forks(t_p *p);
void	ft_unlock_forks(t_p *p);

bool	ft_end(t_p *p);
bool	ft_end_dead(t_p *p);

time_t	ft_get_time(void);
void	ft_set_status(t_main *m, int status);
int		ft_get_status(t_main *m);
void	ft_print(t_p *p, char *text);
void	ft_usleep(int time);

#endif
