/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:54:42 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/12 16:36:58 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*check_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (philo->game->game_over != 1)
	{
		if (philo->state == thinking)
			ph_may_eat(philo);
		else if (philo->state == eating)
			ph_can_eat(philo);
		else if (philo->state == sleeping)
			ph_can_sleep(philo);
	}
	return (NULL);
}

void	ph_may_eat(t_philo *p)
{
	dead_checker(p);
	full_checker(p);
	if (p->game->game_over != 1)
	{
		pthread_mutex_lock(&p->game->mut_queue);
		if (p->id == p->game->queue[0] && is_fork_available(p))
			ph_takes_fork(p);
		pthread_mutex_unlock(&p->game->mut_queue);
	}
}

void	ph_can_eat(t_philo *p)
{
	if (p->game->game_over != 1)
	{
		printer(p, "\033[31mis eating \xF0\x9F\x8D\x9D");
		p->last_meal = get_time();
		p->count_meal++;
		if (p->count_meal == p->game->param->n_eat && p->game->counter_on)
		{
			pthread_mutex_lock(&p->game->mut_full);
			p->game->full++;
			if (p->game->counter_on && p->game->full == p->game->param->n_philo)
			{
				p->game->game_over = 1;
				pthread_mutex_lock(&p->game->mut_print);
				printf("\033[3m\033[35mEveryone is full of spaghetti!\n");
				pthread_mutex_unlock(&p->game->mut_full);
				pthread_mutex_unlock(&p->game->mut_print);
				stop_game(p->game);
				exit (-1);
			}
			pthread_mutex_unlock(&p->game->mut_full);
		}
		ft_usleep(p->game->param->t_to_eat, p);
		ph_drop_fork(p);
		p->state = sleeping;
	}
}

void	ph_can_sleep(t_philo *p)
{
	if (p->game->game_over != 1)
	{
		printer(p, "\033[35mis sleeping \xF0\x9F\x98\xB4");
		ft_usleep (p->game->param->t_to_sleep, p);
		printer(p, "\033[34mis tkinking \xF0\x9F\x93\x96");
		p->state = thinking;
	}
}
