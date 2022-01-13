/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:07:16 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/10 14:36:18 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	check_argv(t_game *game, char **argv)
{
	if (game->param->n_philo < 1 || !nb_in_str(argv[1]))
		return (printf_false(ERR_N_PHILO));
	if (game->param->t_to_die < 1 || !nb_in_str(argv[2]))
		return (printf_false(ERR_T_DIE));
	if (game->param->t_to_eat < 1 || !nb_in_str(argv[3]))
		return (printf_false(ERR_T_EAT));
	if (game->param->t_to_sleep < 1 || !nb_in_str(argv[4]))
		return (printf_false(ERR_T_SLEEP));
	if (game->param->n_eat != -1)
		if (game->param->n_eat < 1 || !nb_in_str(argv[5]))
			return (printf_false(ERR_N_MEAL));
	return (true);
}

bool	nb_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

void	dead_checker(t_philo *philo)
{
	if (philo->game->game_over != 1)
	{
		pthread_mutex_lock(&philo->game->mut_dead);
		if (ph_is_dead(philo))
		{
			philo->game->game_over = 1;
			dead_printer(philo);
			//pthread_mutex_unlock(&philo->game->mut_dead);
			stop_game(philo->game);
			exit (-1);
		}
		pthread_mutex_unlock(&philo->game->mut_dead);
	}
}

void	full_checker(t_philo *philo)
{
	pthread_mutex_lock(&philo->game->mut_gameover);
	if (philo->game->game_over != 1)
	{
		pthread_mutex_lock(&philo->game->mut_full);
		if (philo->game->counter_on && philo->game->full
			== philo->game->param->n_philo)
		{
			philo->game->game_over = 1;
			pthread_mutex_unlock(&philo->game->mut_gameover);
			philo->game->full = 0;
			pthread_mutex_lock(&philo->game->mut_print);
			printf("\033[3m\033[35mEveryone is full of spagetthi!\033[0m\n");
			pthread_mutex_unlock(&philo->game->mut_full);
			//pthread_mutex_unlock(&philo->game->mut_print);
			stop_game(philo->game);
			exit (-1);
		}
		pthread_mutex_unlock(&philo->game->mut_full);
		pthread_mutex_unlock(&philo->game->mut_gameover);
	}
}
