/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:01:56 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 17:50:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
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
	int			n_philo;
	int			ms_alive;
	int			ms_eating;
	int			ms_sleeping;
	int			n_eat_max;
	long		last_meal;
	int			*dead;
	time_t		time;
	pthread_t	thread;
	int			id;
	//mutex
}				t_p;

int		ft_arg(t_p *p, int ac, char **av);

#endif
