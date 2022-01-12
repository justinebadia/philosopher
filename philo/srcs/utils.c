/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:54:54 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/12 16:30:43 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		is_negative;

	is_negative = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * is_negative);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	memory = NULL;
	memory = (void *)malloc(count * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero (memory, count * size);
	return (memory);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}

bool	printf_false(char *str)
{
	printf("\xF0\x9F\x9A\xAB \033[3m\033[31m\033[1m%s\033[0m", str);
	return (false);
}

void	printer(t_philo *p, char *str)
{
	long	current_time;

	dead_checker(p);
	full_checker(p);
	pthread_mutex_lock(&p->game->mut_print);
	if (p->game->game_over != 1)
	{
		current_time = get_time() - p->game->time;
		printf("\033[1m\033[33m%ld %d %s\033[0m\n",current_time, p->id, str);
		pthread_mutex_unlock(&p->game->mut_print);
	}

}

void	dead_printer(t_philo *p)
{
	long long	current_time;
	
	current_time = get_time() - p->game->time;
	pthread_mutex_lock(&p->game->mut_print);
	printf("\033[1m\033[33m%lld %d is dead \xF0\x9F\x92\x80\033[0m\n",current_time, p->id);
	pthread_mutex_unlock(&p->game->mut_print);
}