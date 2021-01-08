# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 00:56:13 by gpaul             #+#    #+#              #
#    Updated: 2021/01/08 14:59:11 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
CC		= gcc -Wall -Wextra -Werror
RM		= rm -rf

SRC	=					

OBJ					=	$(SRC:.c=.o)
INCLUDE				=	libftprintf.h	\

all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C libft
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
bonus: $(OBJ) $(OBJ_BONUS)
	ar -rc $(NAME) $(OBJ_BONUS) $(OBJ)
	ranlib $(NAME)
clean :
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY: all clean fclean re
