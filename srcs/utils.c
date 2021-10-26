/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:51:36 by adelille          #+#    #+#             */
/*   Updated: 2021/10/26 22:02:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_p *p, char *text)
{
	pthread_mutex_lock(p->print_mutex);
	printf("%06ld %d %s\n", ft_get_time() - p->time, p->id + 1, text);
	pthread_mutex_unlock(p->print_mutex);
}

time_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
