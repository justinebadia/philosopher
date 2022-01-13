/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:44:53 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/10 15:31:58 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_free(void *str)
{
	if (str)
		free(str);
	return (NULL);
}

void	stop_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->param->n_philo)
	{
		pthread_mutex_destroy(game->philo[i].mut_fork);
		ft_free (game->philo[i].mut_fork);
		i++;
	}
	ft_free(game->philo);
	ft_free(game->param);
	pthread_mutex_destroy(&game->mut_dead);
	pthread_mutex_destroy(&game->mut_print);
	pthread_mutex_destroy(&game->mut_queue);
	pthread_mutex_destroy(&game->mut_full);
	ft_free(game->queue);
	ft_free(game);
}
