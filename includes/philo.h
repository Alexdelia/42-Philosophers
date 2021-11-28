/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:01:56 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 16:43:15 by adelille         ###   ########.fr       */
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

/*# define TRUE	1
# define FALSE	0*/

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
	long	ms_alive;
	long	ms_eating;
	long	ms_sleeping;
	int		n_eat_max;
}			t_arg;

typedef struct s_main
{
	t_arg			arg;
	struct s_philo	*philosophers;
	pthread_t		*threads;
	long long		time;
	int				status;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	print_mutex;
}					t_main;

typedef struct s_philo
{
	t_arg			arg;
	int				id;
	int				action;
	int				eat_count;
	long long		last_meal;
	pthread_mutex_t	fork_mutex;
	t_main			*main;
}					t_p;

bool	ft_arg(int ac, char **av, t_arg *arg);
bool	ft_init_main(t_main *m);

int		ft_run(t_main *m);
void	*ft_running(void *a);

void	ft_print(t_p *p, char *text);
void	*ft_all_eat(t_p *p);
time_t	ft_get_time(void);
void	ft_usleep(t_p *p, int time);
int		ft_next_fork(t_p *p);

#endif
