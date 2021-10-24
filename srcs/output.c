/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:23:45 by adelille          #+#    #+#             */
/*   Updated: 2021/10/24 17:27:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_put_state(int timestamp_in_ms, int philo_n, char *state)
{
	printf("%d %d %s\n", timestamp_in_ms, philo_n, state); // might be opti by using write
}
