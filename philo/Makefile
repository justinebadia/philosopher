# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 16:42:26 by jbadia            #+#    #+#              #
#    Updated: 2022/01/14 10:04:40 by jbadia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CBOLD   = \033[1m
CITALIC = \033[3m
CBLUE   = \033[34m
CVIOLET = \033[35m
NORMAL 	= \033[0m
CBLUEBG   = \033[44m
CVIOLETBG = \033[45m
CWHITEBG  = \033[47m
CGREEN2  = \033[92m

NAME = philo
SRCS_DIR	= srcs
CC	= gcc 
CFLAGS	= -g -Wall -Wextra -Werror
RM	= rm -rf

C_FILES = srcs/main.c srcs/utils.c srcs/error.c srcs/init.c srcs/time_utils.c\
			srcs/routine.c srcs/queue.c srcs/fork.c srcs/free.c srcs/print.c

O_FILES = $(C_FILES:.c=.o)

.c.o :
	@${CC} ${CFLAGS} -I. -c $< -o $@

all	:		$(NAME)
	@echo "\n\n\033[92m\033[1m\xF0\x9F\x8D\x9D Philo compiled \xF0\x9F\x8D\x9D\033[0m\n\n"

$(NAME) : $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -lpthread -o $@

clean : 
	@$(RM) $(O_FILES)

fclean : clean
	@$(RM) $(NAME)

re : fclean all


.PHONY: all clean fclean re
