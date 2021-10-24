/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:56:43 by adelille          #+#    #+#             */
/*   Updated: 2021/10/24 17:36:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_p	p;
	// eating -> sleeping -> thinking

	// av: n_philo, ms_alive, ms_eating, ms_sleeping, optional: n_eating_for_each then stop

	if (ft_arg(&p, ac, av) == FALSE)
		return (1);
}
