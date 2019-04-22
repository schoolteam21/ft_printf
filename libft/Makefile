# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 19:45:03 by wjeyne-d          #+#    #+#              #
#    Updated: 2019/02/13 21:57:33 by wjeyne-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HDIR = includes
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) -I $(HDIR)
	ar rcs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
