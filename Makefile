# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 00:56:13 by gpaul             #+#    #+#              #
#    Updated: 2021/01/11 16:18:09 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I$(INC_PATH)

SRC_PATH = ./srcs
INC_PATH = ./include
OBJ_PATH = ./obj

INC_NAME = ft_printf.h, libft/libft.a

SRC_NAME = ft_printf.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf ./obj $(NAME)

re: fclean all

.PHONY: all clean fclean re
