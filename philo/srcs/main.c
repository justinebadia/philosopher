/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:54:51 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/10 15:33:48 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


void print_queue(int *queue)
{
	int i;

	i = 0;
	while (queue[i] != '\0')
	{
		printf("%d \n", queue[i]);
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 5 && argc != 6)
		return (printf_false(ERR_ARGC));
	game = init_game(argv, game);
	if (!check_argv(game, argv))
	{
		stop_game(game);
		return (-1);
	}
	if (game->param->n_philo == 1)
	{
		while (game->game_over != 1)
		{
			printer(game->philo, "\033[36mhas taken a fork\xF0\x9F\x8D\xB4");
			ft_usleep(game->param->t_to_die, game->philo);
			printer(game->philo, "is dead \xF0\x9F\x92\x80");
			game->game_over = 1;
		}

	}
	else
		create_thread(game);
	stop_game(game);
	return (0);
}

