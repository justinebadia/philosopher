/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:05:57 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/12 13:36:24 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long long time_now, t_philo *philo)
{
	long long	time;

	time = get_time();
	while (get_time() - time < time_now)
	{
		dead_checker(philo);
		full_checker(philo);
		usleep(250);
	}
}
