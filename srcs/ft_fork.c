/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:26:08 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 18:53:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	ft_lock_forks(t_p *p)
{
	pthread_mutex_lock(&p->fork_mutex);
	ft_print(p, FORK);
	if (ft_end(p))
		return (false);
	if (p->main->arg.n_philo > 1)
	{
		if (p->id == p->main->arg.n_philo)
			pthread_mutex_lock(&p->main->philosophers[0].fork_mutex);
		else
			pthread_mutex_lock(&p->main->philosophers[p->id].fork_mutex);
	}
	ft_print(p, FORK);
	return (true);
}

void	ft_unlock_forks(t_p *p)
{
	pthread_mutex_unlock(&p->fork_mutex);
	if (p->main->arg.n_philo == 1)
		return ;
	if (p->id == p->main->arg.n_philo)
		pthread_mutex_unlock(&p->main->philosophers[0].fork_mutex);
	else
		pthread_mutex_unlock(&p->main->philosophers[p->id].fork_mutex);
}
