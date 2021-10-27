/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:56:43 by adelille          #+#    #+#             */
/*   Updated: 2021/10/27 15:29:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_p				*p;
	t_p				a;
	pthread_mutex_t	*mutex;
	int				i;

	// eating -> sleeping -> thinking

	// av: n_philo, ms_alive, ms_eating, ms_sleeping, optional: n_eating_for_each then stop

	if (ft_arg(&a, ac, av) == FALSE)
		return (1);
	mutex = ft_init_mutex(&a);
	p = ft_init_philo(&a, mutex);
	// launch % 2 == 0 then == 1
	// check if only one philosophers can crash the program
	ft_run(p);
	i = 0;
	while (i < p->n_philo)
	{
		pthread_mutex_destroy(&p[0].mutex[i]);
		i++;
	}
	free(p->ag_mutex);
	free(p->av_mutex);
	free(p->print_mutex);
	free(p);
	free(mutex);
	return (0);
}
