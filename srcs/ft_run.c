/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:03 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 18:14:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_thread(void *a)
{
	t_p	*p;
	int	i;

	p = (t_p *)a;
	while (1)
	{
		i = 0;
		while (i < p->n_philo)
		{
			//pthread_mutex_lock p
			if (*p->dead == p->n_philo * p->n_eat_max);
				return (NULL);
			//pthread_mutex_lock &p[i]
			if (ft_get_time() - p[i].last_meal > p->ms_alive)
			{
				ft_print(DEAD, &p[i]);
				*p->dead = TRUE;
				return (NULL);
			}
			//pthread_mutex_unlock &p[i]
			//pthread_mutex_unlock p
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

static void	ft_half_thread(t_p *p, int *dead, time_t time, int i)
{
	while (i < p->n_philo)
	{
		p[i].last_meal = ft_get_time();
		p[i].time = time;
		p[i].dead = dead;
		pthread_create(&(p[i].thread), NULL, /*ft_???*/, &p[i]);
		pthread_detach(p[i].thread);
		i += 2;
	}
}

int	ft_run(t_p *p)
{
	pthread_t	thread;
	time_t		time;
	int			dead;
	int			i;

	dead = FALSE;
	ft_half_thread(p, &dead, time, 0);
	// usleep
	ft_half_thread(p, &dead, time, 1);
	pthread_create(&thread, NULL, ft_check_thread, p);
	pthread_join(thread, NULL);
	i = 0;
	while (i < p->n_philo)
	{
		pthread_detach(p[i].thread);
		i++;
	}
}
