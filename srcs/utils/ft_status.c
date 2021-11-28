/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:58:24 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 17:01:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_set_status(t_main *m, int status)
{
	pthread_mutex_lock(&m->status_mutex);
	m->status = status;
	pthread_mutex_unlock(&m->status_mutex);
}

int	ft_get_status(t_main *m)
{
	int	tmp;

	pthread_mutex_lock(&m->status_mutex);
	tmp = m->status;
	pthread_mutex_unlock(&m->status_mutex);
	return (tmp);
}
