/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:47:28 by adelille          #+#    #+#             */
/*   Updated: 2021/11/29 16:33:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/*static char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	streq(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}*/

/*void	ft_print(t_p *p, char *text)
{
	char		buff[50];
	char		dest[4048];

	pthread_mutex_lock(&p->main->print_mutex);
	pthread_mutex_lock(&p->main->status_mutex);
	if (p->main->status == STOP)
	{
		pthread_mutex_unlock(&p->main->status_mutex);
		pthread_mutex_unlock(&p->main->print_mutex);
		return ;
	}
	if (streq(text, DEAD))
		p->main->status = STOP;
	pthread_mutex_unlock(&p->main->status_mutex);
	ft_itoa(ft_get_time() - p->main->time, dest);
	ft_strcat(dest, "\t");
	ft_strcat(dest, ft_itoa(p->id, buff));
	ft_strcat(dest, " ");
	ft_strcat(dest, text);
	ft_strcat(dest, "\n");
	write(STDOUT_FILENO, dest, ft_strlen(dest));
	pthread_mutex_unlock(&p->main->print_mutex);
}*/
