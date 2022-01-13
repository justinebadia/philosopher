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
