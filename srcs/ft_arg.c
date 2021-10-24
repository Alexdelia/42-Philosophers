/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:31:18 by adelille          #+#    #+#             */
/*   Updated: 2021/10/24 17:53:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_num(char *n)
{
	int	i;

	i = 0;
	if (n[0] && (n[0] == '-' || n[0] == '+'))
		i++;
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			return (printf("Error: \"%s\" is not a valid number.\n", n) * 0);
		i++;
	}
	if (n[0] && n[0] == '-')
		printf("Warning: Be aware that \"%s\" is negative.\n", n);
	return (TRUE);
}

int	ft_arg(t_p *p, int ac, char **av)
{
	int	i;

	if (ac != 5 || ac != 6)
		return (FALSE);
	i = 1;
	while (i < ac)
	{
		if (ft_is_num(av[i]) == FALSE)
			return (FALSE);
		i++;
	}
	p->n_philo = ft_atoi(av[1]);
	p->ms_alive = ft_atoi(av[2]);
	p->ms_eating = ft_atoi(av[3]);
	p->ms_sleeping = ft_atoi(av[4]);
	p->n_eat_max = -1;
	if (ac == 6)
		p->n_eat_max = ft_atoi(av[5]);
	return (TRUE);
}
