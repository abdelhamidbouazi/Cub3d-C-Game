# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 20:37:18 by abouazi           #+#    #+#              #
#    Updated: 2023/07/15 02:03:16 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CHECK = parser/Check/colors.c parser/Check/elements.c parser/Check/extension.c \
		parser/Check/floor_ciel.c parser/Check/headers.c parser/Check/textures.c

FILL = parser/Fill/colors.c parser/Fill/textures.c parser/Fill/map.c

READ = parser/Read/map.c

UTILS = utils/ft_atoi.c utils/ft_error.c utils/ft_split.c utils/ft_strcmp.c \
		utils/ft_strncmp.c utils/ft_substr.c utils/ft_strndup.c \
		parser/utils/free_split.c utils/ft_free.c

GNL = gnl/gnl.c gnl/gnl_utils.c

PARSING = parser/parser.c ${CHECK} ${FILL} ${READ} ${UTILS} ${GNL}

MOVE = move/left.c  move/right.c move/forward.c move/back.c move/rotate_left.c move/rotate_right.c move/esc.c \
		move/init_keys.c move/press.c move/release.c move/move.c

CAST = cast/raycastingh.c cast/raycastingv.c cast/distance.c cast/is_wall.c cast/raycasting.c \
		cast/create_img.c cast/normalizer.c

RENDER = render/draw3d.c render/my_mlx.c render/wall.c render/textures.c render/draw.c

SRC = cub3d.c $(MOVE) $(CAST) $(RENDER) $(PARSING)

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
