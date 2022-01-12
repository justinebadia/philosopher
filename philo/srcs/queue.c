/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:36:04 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/05 15:04:52 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_waiting_queue(t_game *game, long n_ph)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n_ph)
	{
		game->queue[j] = game->philo[i].id;
		i += 2;
		j++;
	}
	i = 1;
	while (i < n_ph)
	{
		game->queue[j] = game->philo[i].id;
		i += 2;
		j++;
	}
}

void	go_back_queue(t_game *game)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = game->queue[0];
	while (i < game->param->n_philo - 1)
	{
		game->queue[i] = game->queue[i + 1];
		i++;
	}
	game->queue[i] = tmp;
}