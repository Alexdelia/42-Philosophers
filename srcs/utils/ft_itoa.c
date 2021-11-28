/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:58:28 by adelille          #+#    #+#             */
/*   Updated: 2021/11/28 19:59:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_nbrlen(int n)
{
	int			i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	ft_compute(unsigned int n, char *dest, int len)
{
	while (len >= 0)
	{
		dest[len--] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_itoa(time_t n, char *dest)
{
	int		len;

	len = ft_nbrlen(n);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
	{
		dest[0] = '-';
		ft_compute((unsigned int) -n, dest + 1, len - 2);
	}
	else
		ft_compute((unsigned int)n, dest, len - 1);
	return (dest);
}
