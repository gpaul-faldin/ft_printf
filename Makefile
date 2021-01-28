# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 00:56:13 by gpaul             #+#    #+#              #
#    Updated: 2021/01/28 22:37:27 by gpaul            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -I$(INC_PATH)

SRC_PATH = ./srcs
INC_PATH = ./include
OBJ_PATH = ./obj

INC_NAME = ft_printf.h

SRC_NAME =		ft_printf.c			\
				ft_print_flags.c	\
				ft_print_char.c		\
				ft_flag_str.c		\
				ft_print_nbr.c		\
				ft_flag_nbr.c		\
				ft_flag_ui.c		\
				ft_flag_hex.c		\
				ft_flag_ptr.c		\
				ft_print_utils.c	\
				ft_print_utils2.c	\
				ft_print_utils3.c	\
				ft_itoa_ui.c		\

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf ./obj $(NAME)

re: fclean all

.PHONY: all clean fclean re
