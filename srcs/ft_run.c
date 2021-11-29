/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:03 by adelille          #+#    #+#             */
/*   Updated: 2021/11/29 18:46:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_p *p)
{
	time_t	start;

	if (!ft_lock_forks(p))
		while (!ft_end(p))
			usleep(USLEEP);
	if (ft_end(p))
	{
		ft_unlock_forks(p);
		return ;
	}
	p->last_meal = ft_get_time() - p->main->time;
	ft_print(p, EAT);
	start = ft_get_time();
	//while (ft_end(p) == false && (ft_get_time() - start) <= p->main->arg.ms_eating)
	//	usleep(USLEEP);
	usleep((unsigned int)p->main->arg.ms_eating * OPTI);
	ft_unlock_forks(p);
	p->eat_count++;
	p->action = SLEEPING;
}

void	ft_sleep(t_p *p)
{
	time_t	start;

	start = ft_get_time();
	ft_print(p, SLEEP);
	//while (!ft_end(p) && ft_get_time() - start <= p->main->arg.ms_sleeping)
	//	usleep(USLEEP);
	usleep((unsigned int)p->main->arg.ms_eating * OPTI);
	p->action = THINKING;
}

void	ft_think(t_p *p)
{
	ft_print(p, THINK);
	p->action = EATING;
}

void	*ft_running(t_p *p)
{
	while (!ft_end(p))
	{
		if (p->action == EATING)
			ft_eat(p);
		else if (p->action == SLEEPING)
			ft_sleep(p);
		else if (p->action == THINKING)
			ft_think(p);
	}
	if (ft_end_dead(p) && ft_get_status(p->main) != STOP)
	{
		ft_print(p, DEAD);
		ft_set_status(p->main, STOP);
	}
	return (NULL);
}

void	*ft_launcher(t_p *p)
{
	int	status;

	while (1)
	{
		status = ft_get_status(p->main);
		if (status == ALL || (p->id % 2 && status == HALF))
			return (ft_running(p));
		usleep(USLEEP);
	}
	return (NULL);
}
