/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:54:54 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/12 16:30:43 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		printf("\033[1m\033[33m%ld %d %s\033[0m\n", current_time, p->id, str);
		pthread_mutex_unlock(&p->game->mut_print);
	}
}

void	dead_printer(t_philo *p)
{
	long long	current_time;

	current_time = get_time() - p->game->time;
	pthread_mutex_lock(&p->game->mut_print);
	printf("\033[1m\033[33m%lld %d is dead \xF0\x9F\x92\x80\033[0m\n",
		current_time, p->id);
	pthread_mutex_unlock(&p->game->mut_print);
}
