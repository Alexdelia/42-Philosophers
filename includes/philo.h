/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:01:56 by adelille          #+#    #+#             */
/*   Updated: 2021/10/27 23:39:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
//# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE	1
# define FALSE	0

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"died"

typedef struct s_philo
{
	int				n_philo;
	long			ms_alive;
	long			ms_eating;
	long			ms_sleeping;
	int				n_eat_max;
	long			last_meal;
	int				*dead;
	time_t			time;
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*av_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	lm_mutex;
}					t_p;

int				ft_arg(t_p *p, int ac, char **av);
int				ft_run(t_p *p);

t_p				*ft_init_philo(t_p *a, pthread_mutex_t *mutex);
pthread_mutex_t	*ft_init_mutex(t_p *a);

void			ft_print(t_p *p, char *text);
void			*ft_all_eat(t_p *p);
time_t			ft_get_time(void);
void			ft_usleep(t_p *p, int time);
int				ft_next_fork(t_p *p);

#endif
