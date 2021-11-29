/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:51:36 by adelille          #+#    #+#             */
/*   Updated: 2021/11/29 19:02:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

time_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print(t_p *p, char *text)
{
	pthread_mutex_lock(&p->main->status_mutex);
	if (p->main->status == STOP)
	{
		pthread_mutex_unlock(&p->main->status_mutex);
		return ;
	}
	pthread_mutex_unlock(&p->main->status_mutex);
	pthread_mutex_lock(&p->main->print_mutex);
	printf("%ld\t%d %s\n", ft_get_time() - p->main->time, p->id, text);
	pthread_mutex_unlock(&p->main->print_mutex);
}

void	ft_usleep(int time)
{
	time_t	t;
	time_t	stop;

	t = ft_get_time();
	stop = t + time;
	while (ft_get_time() < stop)
		usleep(100);
}
