/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:36:03 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 18:24:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_p *p)
{
	time_t	start;

	//fork
}

void	*ft_running(t_p *p)
{
	while (!ft_end(p))
	{
		ft_eat(p);
		ft_sleep(p);
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
		if (status == ALL || (!(p->id % 2) && status == HALF))
			return (ft_running(p));
		usleep(300);
	}
	return (NULL);
}

/*int	ft_eat(t_p *p)
{
	pthread_mutex_lock(&p->mutex[p->id]);
	ft_print(p, FORK);
	pthread_mutex_lock(&p->mutex[ft_next_fork(p)]);
	ft_print(p, FORK);
	pthread_mutex_lock(&p->lm_mutex);
	ft_print(p, EAT);
	p->last_meal = ft_get_time();
	pthread_mutex_unlock(&p->lm_mutex);
	ft_usleep(p, p->ms_eating);
	pthread_mutex_lock((p->dead_mutex));
	if (*p->dead != -1)
		*(p->dead) += 1;
	else
		return (FALSE);
	pthread_mutex_unlock((p->dead_mutex));
	pthread_mutex_unlock(&p->mutex[p->id]);
	if (p->n_philo != 1)
		pthread_mutex_unlock(&p->mutex[ft_next_fork(p)]);
	return (TRUE);
}*/

/*void	*ft_running(void *a)
{
	t_p	*p;
	int	i;

	p = (t_p *)a;
	i = 0;
	while (i < p->n_eat_max || (p->n_eat_max == -1))
	{
		pthread_mutex_lock((p->dead_mutex));
		if (*p->dead == -1)
			return (NULL);
		pthread_mutex_unlock((p->dead_mutex));
		if (ft_eat(p) == FALSE)
			return (NULL);
		ft_print(p, SLEEP);
		ft_usleep(p, p->ms_sleeping);
		pthread_mutex_lock((p->dead_mutex));
		if (*p->dead == -1)
			return (NULL);
		else
			ft_print(p, THINK);
		pthread_mutex_unlock((p->dead_mutex));
		i++;
	}
	return (NULL);
}*/

/*void	*ft_check_thread(void *a)
{
	t_p	*p;
	int	i;

	p = (t_p *)a;
	while (1)
	{
		i = -1;
		while (++i < p->n_philo)
		{
			pthread_mutex_lock((p->dead_mutex));
			if (*p->dead == p->n_philo * p->n_eat_max)
				return (ft_all_eat(p));
			pthread_mutex_lock(&p[i].lm_mutex);
			if (ft_get_time() - p[i].last_meal > p->ms_alive)
			{
				ft_print(&p[i], DEAD);
				*p->dead = TRUE;
				return (NULL);
			}
			pthread_mutex_unlock(&p[i].lm_mutex);
			pthread_mutex_unlock((p->dead_mutex));
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
		pthread_create(&(p[i].thread), NULL, ft_running, &p[i]);
		pthread_join(p[i].thread, NULL);
		i += 2;
	}
}

int	ft_run(t_p *p)
{
	pthread_t	thread;
	time_t		time;
	int			dead;

	time = ft_get_time();
	dead = FALSE;
	ft_half_thread(p, &dead, time, 0);
	ft_usleep(p, 10);
	ft_half_thread(p, &dead, time, 1);
	pthread_create(&thread, NULL, ft_check_thread, p);
	pthread_join(thread, NULL);
	return (0);
}*/
