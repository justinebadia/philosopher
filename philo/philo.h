/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:07:16 by jbadia            #+#    #+#             */
/*   Updated: 2022/01/10 14:36:18 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

# define ERR_N_PHILO "At least, one philosopher is needed to play\n"
# define ERR_T_DIE "Time to die must be set at least at one integer\
greater than 0\n"
# define ERR_T_EAT "Time to eat must be set at least at one integer\
greater than 0\n"
# define ERR_T_SLEEP "Time to sleep must be set at least at one integer\
greater than 0\n"
# define ERR_N_MEAL "Number of meal must be set at least at one integer\
greater than 0\n"
# define ERR_ARGC "Please, respect the following rules : ./philo [nb_de_philo]\
[time_to_die] [time_to_eat] [time_to_sleep] [nb_time_must_eat]\n"

typedef enum e_state
{
	eating,
	sleeping,
	thinking,
	dead,
}		t_state;

typedef struct s_param
{
	long	n_philo;
	long	n_eat;
	long	t_to_die;
	long	t_to_eat;
	long	t_to_sleep;
}			t_param;

typedef struct s_philo
{
	struct s_game	*game;
	int				fork;
	int				id;
	int				count_meal;
	long long		last_meal;
	pthread_mutex_t	*mut_fork;
	t_state			state;
}				t_philo;

typedef struct s_game
{
	int				game_over;
	int				last_philo;
	int				*queue;
	long			time;
	int				full;
	int				counter_on;
	t_param			*param;
	t_philo			*philo;
	pthread_mutex_t	mut_full;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_queue;
	pthread_mutex_t	mut_dead;
	pthread_mutex_t	mut_gameover;
}				t_game;

int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
bool		printf_false(char *str);
void		printer(t_philo *p, char *str);
void		dead_printer(t_philo *p);

bool		check_argv(t_game *game, char **argv);
bool		nb_in_str(char *str);

t_game		*init_game(char **argv, t_game *game);
void		*init_param(t_game *game, char **argv);
void		*create_thread(t_game *game);
void		*init_philo(t_game *game);

long long	get_time(void);
void		ft_usleep(long long time_now, t_philo *philo);

void		*check_routine(void *philo);
void		ph_may_eat(t_philo *p);
void		ph_can_eat(t_philo *p);
void		ph_can_sleep(t_philo *p);
void		dead_checker(t_philo *philo);
void		full_checker(t_philo *philo);

void		go_back_queue(t_game *game);
void		init_waiting_queue(t_game *game, long n_ph);

bool		is_fork_available(t_philo *ph);
void		ph_takes_fork(t_philo *philo);
void		ph_drop_fork(t_philo *p);
bool		ph_is_full(t_philo *p);
bool		ph_is_dead(t_philo *p);

void		*ft_free(void *str);
void		stop_game(t_game *game);

#endif