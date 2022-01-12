/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:04:06 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/12 14:00:30 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	is_fork_available(t_philo *ph)
{
	if (ph->id == ph->game->last_philo)
	{
		if (ph->fork == 0 && ph->game->philo[0].fork == 0)
			return (true);
	}
	else
	{
	if (ph->fork == 0 && ph->game->philo[ph->id].fork == 0)
		return (true);
	}
	return (false);
}

void	ph_drop_fork(t_philo *p)
{
	p->fork = 0;
	pthread_mutex_unlock(p->mut_fork);
	if (p->id == p->game->last_philo)
	{
		p->game->philo[0].fork = 0;
		pthread_mutex_unlock(p->game->philo[0].mut_fork);
	}
	else
	{
		p->game->philo[p->id].fork = 0;
		pthread_mutex_unlock(p->game->philo[p->id].mut_fork);
	}
}

void	ph_takes_fork(t_philo *p)
{
	pthread_mutex_lock(p->mut_fork);
	p->fork = 1;
	printer(p, "\033[36mhas taken a fork\xF0\x9F\x8D\xB4");
	if (p->id == p->game->last_philo)
	{
		pthread_mutex_lock(p->game->philo[0].mut_fork);
		p->game->philo[0].fork = 1;
		printer(p, "\033[36mhas taken a fork\xF0\x9F\x8D\xB4");
		p->state = eating;
		go_back_queue(p->game);
	}
	else
	{
		pthread_mutex_lock(p->game->philo[p->id].mut_fork);
		p->game->philo[p->id].fork = 1;
		printer(p, "\033[36mhas taken a fork\xF0\x9F\x8D\xB4");
		p->state = eating;
		go_back_queue(p->game);
	}
	
}

bool	ph_is_full(t_philo *p)
{
//	pthread_mutex_lock(&p->game->mut_full);
	if (p->count_meal == p->game->param->n_eat)
	{
	//	pthread_mutex_unlock(&p->game->mut_full);
		return (true);
	}
//	pthread_mutex_unlock(&p->game->mut_full);
	return (false);
}

bool	ph_is_dead(t_philo *p)
{
	long long current_time;

	current_time = get_time();
	if (p->last_meal == 0 && (current_time - p->game->time >= p->game->param->t_to_die))
		return (true);
	else if (p->last_meal == 0)
		return (false);
	else if (current_time - p->last_meal >= p->game->param->t_to_die)
		return (true);
	return(false);
}