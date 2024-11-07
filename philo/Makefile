# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:33:26 by ael-qori          #+#    #+#              #
#    Updated: 2024/04/30 10:32:52 by ael-qori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
RM = rm -rf
CFLAGS= -Wall -Wextra -Werror -pthread# -g -fsanitize=address
SRC = ./philo.c\
	  ./check_args/check_args.c\
	  ./print/errors.c\
	  ./print/status.c\
	  ./libft/ft_atoi.c\
	  ./libft/ft_calloc.c\
	  ./init_data/init_alloc.c\
	  ./init_data/init_data.c\
	  ./init_data/init_mutex.c\
	  ./init_data/init_philo.c\
	  ./action/action.c\
	  ./action/philosophers.c\
	  ./action/api.c\
	  ./time/time.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
