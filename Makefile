# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 14:28:27 by ajubert           #+#    #+#              #
#    Updated: 2016/05/10 15:16:03 by ajubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		push_swap

COMPILER=	gcc
FLAG=		-Wall -Werror -Wextra
LIB=		libft.a
INCLUDES=	-I ./libft/includes/

SRC_C=	main.c\
		ft_push.c\
		ft_list_push_swap.c\
		ft_rotate_reverse.c\
		rr.c\
		ft_swap.c\
		push_swap_calc.c\
		display_list.c\
		test_a.c\
		tri_a_and_b.c\
		test_swap_a.c\
		tri_small_list.c\
		tri_aa.c

SRC_O=		$(SRC_C:.c=.o)

all: libft.a libft.h $(NAME)

$(NAME): $(SRC_O)
	$(COMPILER) -o $(NAME) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======PUSH_SWAP HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAG) -c $<

libft.a:
	@echo "\033[32m==================================="
	@echo "==========COMPILING LIBFT=========="
	@echo "===================================\033[0m"
	make re -C ./libft/
	cp ./libft/libft.a .
	make fclean -C ./libft/

libft.h:
	cp ./libft/libft/libft.h .
	cp ./libft/libft/get_next_line.h .
	cp ./libft/printf/ft_printf.h .

clean:
	@echo "\033[33m==========REMOVING OBJ FILES==========\033[0m"
	rm -rf $(SRC_O)

fclean: clean
	@echo "\033[31m==========REMOVING BIN FILES==========\033[0m"
	rm -rf $(NAME) libft.a
	rm -rf $(NAME) libft.h
	rm -rf $(NAME) get_next_line.h
	rm -rf $(NAME) ft_printf.h

re: fclean all
