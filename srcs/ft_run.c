/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:03 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 19:33:07 by adelille         ###   ########.fr       */
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
	p->last_meal = p->main->time - ft_get_time();
	ft_print(p, EAT);
	start = ft_get_time();
	while (!ft_end(p) && start - ft_get_time() >= p->main->arg.ms_eating)
		usleep(USLEEP);
	ft_unlock_forks(p);
	p->eat_count++;
	p->action = SLEEPING;
}

void	ft_sleep(t_p *p)
{
	time_t	start;

	start = ft_get_time();
	ft_print(p, SLEEP);
	while (!ft_end(p) && start - ft_get_time() >= p->main->arg.ms_sleeping)
		usleep(USLEEP);
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
	if (ft_end_dead(p))
		ft_print(p, DEAD);
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
