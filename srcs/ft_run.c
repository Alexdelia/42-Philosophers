/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:03 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 17:43:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_run(t_p *p)
{
	pthread_t	thread;
	int			dead;
	int			i;

	dead = FALSE;
	ft_half_thread(p, 0);
	// usleep
	ft_half_thread(p, 1);
	// pthread_create(&thread, NULL, ft_???, p);
	// pthread_join(thread, NULL);
	i = 0;
	while (i < p->nb_philo)
	{
		//pthread_detach(p[i].thread);
		i++;
	}
}
