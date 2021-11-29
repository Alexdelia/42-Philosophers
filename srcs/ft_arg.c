/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:31:18 by adelille          #+#    #+#             */
/*   Updated: 2021/11/29 18:50:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + (nptr[i++] - 48);
	return (res * neg);
}

static bool	ft_is_num(char *n)
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
	return (true);
}

bool	ft_arg(int ac, char **av, t_arg *arg)
{
	int	i;

	if (ac != 5 && ac != 6)
		return ((printf("Error: wrong number of arguments\n")
				+ printf("Argument should be in this format:\n./philo [total")
				+ printf("_philo] [ms_death] [ms_eat] [ms_sleep] [eat_max]\n"))
			* 0);
	i = 1;
	while (i < ac)
	{
		if (ft_is_num(av[i]) == false)
			return (false);
		i++;
	}
	arg->n_philo = ft_atoi(av[1]);
	if (arg->n_philo <= 0)
		return (printf("Error: number of philosophers <= 0\n") * 0);
	arg->ms_alive = ft_atoi(av[2]);
	arg->ms_eating = ft_atoi(av[3]);
	arg->ms_sleeping = ft_atoi(av[4]);
	arg->n_eat_max = -1;
	if (ac == 6)
		arg->n_eat_max = ft_atoi(av[5]);
	return (true);
}
