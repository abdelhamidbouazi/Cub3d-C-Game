# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 20:37:18 by abouazi           #+#    #+#              #
#    Updated: 2023/07/09 08:01:56 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D


MOVE = move/left.c  move/right.c move/forward.c move/back.c move/rotate_left.c move/rotate_right.c move/esc.c
CAST = cast/raycastingh.c cast/raycastingv.c
SRC = main.c $(MOVE) $(CAST) 
INCL = cub3d.h

CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX =   -lmlx -framework OpenGL -framework AppKit
RM = rm -f

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ)  $(FLAGS_MLX)  -o $(NAME)

%.o:%.c $(INCL)
	$(CC) $(FLAGS) -c $< -o $@

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)


re : fclean all

run : fclean all
	./cub3D
