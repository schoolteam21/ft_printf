# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhelly <dhelly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 15:46:42 by dhelly            #+#    #+#              #
#    Updated: 2019/03/27 15:28:50 by wjeyne-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LNAME = libft
SRCS = ft_flags.c ft_printf.c ft_itoa_base_uns.c ft_print_def.c ft_width.c ft_maker.c ft_hash_maker.c ft_kostili.c ft_precision.c ft_print_float.c ft_move_size.c ft_check_err.c
OBJ = *.o
OBJ2 = libft/ft_*.o
FLAGS = -Wall -Wextra -Werror
INC = -I. -I./libft/includes

all: $(NAME)

$(NAME):
	@make -C libft fclean && make -C libft
	@gcc $(FLAGS) -c $(SRCS) $(INC)
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJ2)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a

re: fclean all
