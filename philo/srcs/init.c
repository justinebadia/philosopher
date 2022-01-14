/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:00:16 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/14 10:29:05 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*Initie la structure avec les nombres entrés en commande*/
t_game	*init_game(char **argv, t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	game->game_over = 0;
	game->time = get_time();
	pthread_mutex_init(&game->mut_print, NULL);
	pthread_mutex_init(&game->mut_queue, NULL);
	pthread_mutex_init(&game->mut_full, NULL);
	pthread_mutex_init(&game->mut_dead, NULL);
	pthread_mutex_init(&game->mut_gameover, NULL);
	init_param(game, argv);
	init_philo(game);
	game->last_philo = game->param->n_philo;
	game->queue = ft_calloc(game->param->n_philo, sizeof(int));
	init_waiting_queue(game, game->param->n_philo);
	if (argv[5])
	{
		game->counter_on = 1;
		game->full = 0;
	}
	else
	{
		game->counter_on = -1;
		game->full = -1;
	}
	return (game);
}

void	*init_param(t_game *game, char **argv)
{
	t_param	*param;

	param = NULL;
	param = ft_calloc(1, sizeof(t_param));
	if (!param)
		return (NULL);
	param->n_philo = ft_atoi(argv[1]);
	param->t_to_die = ft_atoi(argv[2]);
	param->t_to_eat = ft_atoi(argv[3]);
	param->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		param->n_eat = ft_atoi(argv[5]);
	else
		param->n_eat = -1;
	game->param = (t_param *)param;
	return (NULL);
}

void	*init_philo(t_game *game)
{
	int	i;

	i = 0;
	game->philo = ft_calloc(game->param->n_philo, sizeof(t_philo));
	if (!game->philo)
		return (NULL);
	while (i < game->param->n_philo)
	{
		game->philo[i].id = i + 1;
		game->philo[i].state = thinking;
		game->philo[i].fork = 0;
		game->philo[i].mut_fork
			= ft_calloc(game->param->n_philo, sizeof(pthread_mutex_t));
		pthread_mutex_init(game->philo[i].mut_fork, NULL);
		game->philo[i].count_meal = 0;
		game->philo[i].last_meal = 0;
		game->philo[i].game = game;
		i++;
	}
	return (NULL);
}

void	*create_thread(t_game *game)
{
	pthread_t	*t_ph;
	int			i;

	t_ph = ft_calloc(game->param->n_philo, sizeof(pthread_t));
	if (!t_ph)
		return (NULL);
	i = 0;
	while (i < game->param->n_philo)
	{
		if (pthread_create(&t_ph[i], NULL, check_routine, &game->philo[i]) != 0)
			printf("Thread error\n");
		i++;
	}
	while (i > 0)
	{
		i--;
		pthread_join(t_ph[i], NULL);
	}
	stop_game(game);
	free(t_ph);
	return (NULL);
}
