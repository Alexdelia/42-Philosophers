/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:21:00 by adelille          #+#    #+#             */
/*   Updated: 2021/11/18 13:51:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*ft_init_mutex(t_p *a)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * a->n_philo);
	if (!mutex)
		exit(1);
	i = 0;
	while (i < a->n_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

static void	ft_free_malloc_err_mutex(pthread_mutex_t *m[2], int i,
		pthread_mutex_t *mutex)
{
	while (i > 0)
	{
		i--;
		free(m[i]);
	}
	free(mutex);
	exit(1);
}

static t_p	*ft_a_to_p(t_p *a, pthread_mutex_t *mutex,
		pthread_mutex_t *m[2])
{
	t_p	*p;
	int	i;

	p = (t_p *)malloc(sizeof(t_p) * (a->n_philo));
	if (!p)
		ft_free_malloc_err_mutex(m, 2, mutex);
	i = 0;
	while (i < a->n_philo)
	{
		p[i].id = i;
		p[i].n_philo = a->n_philo;
		p[i].ms_alive = a->ms_alive;
		p[i].ms_eating = a->ms_eating;
		p[i].ms_sleeping = a->ms_sleeping;
		p[i].n_eat_max = a->n_eat_max;
		p[i].time = a->time;
		p[i].dead = FALSE;
		p[i].mutex = mutex;
		i++;
	}
	return (p);
}

t_p	*ft_init_philo(t_p *a, pthread_mutex_t *mutex)
{
	t_p				*p;
	pthread_mutex_t	*m[2];
	int				i;

	i = 0;
	while (i < 2)
	{
		m[i] = malloc(sizeof(pthread_mutex_t));
		if (!m[i])
			ft_free_malloc_err_mutex(m, i, mutex);
		pthread_mutex_init(m[i], NULL);
		i++;
	}
	p = ft_a_to_p(a, mutex, m);
	i = 0;
	while (i < a->n_philo)
	{
		p[i].dead_mutex = m[0];
		p[i].print_mutex = m[1];
		pthread_mutex_init(&p[i].lm_mutex, NULL);
		i++;
	}
	return (p);
}
