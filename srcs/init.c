/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:21:00 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 18:03:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	ft_init_philo(t_main *m)
{
	int	i;

	i = 0;
	while (i < m->arg.n_philo)
	{
		if (pthread_mutex_init(&m->philosophers[i].fork_mutex, NULL) < 0)
		{
			while (i--)
				pthread_mutex_destroy(&m->philosophers[i].fork_mutex);
			return (printf("Error: pthread_mutex_init() failed\n") * 0);
		}
		m->philosophers[i].main = m;
		m->philosophers[i].id = i + 1;
		m->philosophers[i].eat_count = 0;
		m->philosophers[i].last_meal = 0;
		m->philosophers[i].action = EATING;
		if (pthread_create(&m->threads[i], NULL,
				ft_launcher, &m->philosophers[i]) < 0)
			return (printf("Error: pthread_create() failed\n") * 0);
		i++;
	}
	return (true);
}

bool	ft_init_main(t_main *m)
{
	m->philosophers = (t_philo *)malloc(sizeof(t_philo) * m->arg.n_philo);
	if (!m->philosophers)
		return (printf("Error: Malloc failed\n") * 0);
	m->threads = (pthread_t *)malloc(sizeof(pthread_t) * m->arg.n_philo);
	if (!m->threads)
		return (printf("Error: Malloc failed\n") * 0);
	m->status = START;
	if (pthread_mutex_init(&m->status_mutex, NULL) < 0
		|| pthread_mutex_init(&m->print_mutex, NULL) < 0)
		return (printf("Error: pthread_mutex_init() failed\n") * 0);
	if (!ft_init_philo(m))
		return (false);
	return (true);
}
