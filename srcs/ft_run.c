/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:03 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 17:54:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	ft_half_thread(p, 0, &dead);
	// usleep
	ft_half_thread(p, 1, &dead);
	// pthread_create(&thread, NULL, ft_???, p);
	// pthread_join(thread, NULL);
	i = 0;
	while (i < p->n_philo)
	{
		//pthread_detach(p[i].thread);
		i++;
	}
}
