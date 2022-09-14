# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 23:31:23 by zhaddoum          #+#    #+#              #
#    Updated: 2022/09/14 23:42:54 by zhaddoum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = map_creation.c \
movements.c \
movements_utils.c \
map_check.c \
map_creation.c \
get_next_line/get_next_line.c \
main.c \
NAME = Object_so_long.a
COMPILE = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit
AR = ar rcs
OBJ = $(SRC:.c =.o)
HEADER=*.h
RM = rm -rf

all: $(NAME) $(COMPILE)

$(NAME): $(OBJ) $(HEADER)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

$(COMPILE): $(NAME)
	cd ft_printf && Makefile
	$(CC) $(FLAGS) $(NAME) -o $(COMPILE)

clean:
	$(RM) $(OBJ) ft_printf/*.o ft_printf/*.a

fclean: clean
	$(RM) $(NAME) $(COMPILE)
re: fclean all

.PHONY: all clean fclean re