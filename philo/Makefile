# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 16:42:26 by jbadia            #+#    #+#              #
#    Updated: 2022/01/06 14:59:36 by jbadia           ###   ########.fr        #
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
OBJ_DIR	= obj 
SRCS_DIR	= srcs
CC	= gcc 
CFLAGS	= -g -Wall -Wextra -Werror
RM	= rm -rf

C_FILES = srcs/main.c srcs/utils.c srcs/error.c srcs/init.c srcs/time_utils.c\
			srcs/routine.c srcs/queue.c srcs/fork.c srcs/free.c

O_FILES = $(C_FILES:.c=.o)

.c.o :
	@${CC} ${CFLAGS} -c -I. $< -o $@

all	:		$(NAME)

$(NAME) : $(OBJ_DIR) $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -lpthread -o $@

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean : 
	@$(RM) $(O_FILES)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
	