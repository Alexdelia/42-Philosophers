/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:08:15 by adelille          #+#    #+#             */
/*   Updated: 2021/11/29 18:58:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

bool	ft_end_dead(t_p *p)
{
	return ((ft_get_time() - p->main->time) - p->last_meal
		>= p->main->arg.ms_alive);
}

bool	ft_end(t_p *p)
{
	return (ft_end_dead(p) || ft_get_status(p->main) == STOP
		|| (p->main->arg.n_eat_max != -1
			&& p->eat_count >= p->main->arg.n_eat_max));
}
