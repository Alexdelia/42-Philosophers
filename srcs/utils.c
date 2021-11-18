/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:51:36 by adelille          #+#    #+#             */
/*   Updated: 2021/11/18 13:32:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_p *p, char *text)
{
	pthread_mutex_lock(p->print_mutex);
	printf("%ld\t%d %s\n", ft_get_time() - p->time, p->id + 1, text);
	pthread_mutex_unlock(p->print_mutex);
}

void	*ft_all_eat(t_p *p)
{
	printf("%ld\tFinished: everyone ate %d times.\n",
		ft_get_time() - p->time, p->n_eat_max);
	return (NULL);
}

time_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(t_p *p, int time)
{
	time_t	t;
	time_t	stop;

	if (!p || p->dead_mutex == NULL)
		return ;
	t = ft_get_time();
	stop = t + time;
	while (ft_get_time() < stop)
	{
		pthread_mutex_lock(p->dead_mutex);
		if (*p->dead == -1)
			return ;
		pthread_mutex_unlock(p->dead_mutex);
		usleep(100);
	}
}

int	ft_next_fork(t_p *p)
{
	if (p->n_philo == 1)
		pthread_mutex_unlock(&p->mutex[0]);
	if (p->id - 1 < 0)
		return (p->n_philo - 1);
	return (p->id - 1);
}
