/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:56:43 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 17:06:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_clear(t_main m)
{
	int	i;

	pthread_mutex_destroy(&m.status_mutex);
	i = 0;
	while (i < m.arg.n_philo)
	{
		pthread_mutex_destroy(&m.philosophers[i].fork_mutex);
		i++;
	}
	free(m.philosophers);
	free(m.threads);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (!ft_arg(ac, av, &main.arg))
		return (1);
	//main.arg = arg;
	if (!ft_init_main(&main))
		return (2);
	main.time = ft_get_time();
	//ft_run(p);
	
	ft_clear(main);
	return (0);
}
