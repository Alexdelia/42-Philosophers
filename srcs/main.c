/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:56:43 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 15:55:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_p		p;
	t_arg	arg;

	if (!ft_arg(ac, av, &arg))
		return (1);
	mutex = ft_init_mutex(&a);
	p = ft_init_philo(&a, mutex);
	ft_run(p);
	i = 0;
	while (i < p->n_philo)
	{
		pthread_mutex_destroy(&p[0].mutex[i]);
		i++;
	}
	if (p)
	{
		free(p->dead_mutex);
		free(p->print_mutex);
		free(p);
		p = NULL;
	}
	free(mutex);
	return (0);
}
