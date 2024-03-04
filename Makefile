# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkadri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 14:12:47 by mkadri            #+#    #+#              #
#    Updated: 2024/03/04 11:19:30 by mkadri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = main.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
 
all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

.PHONY: all clean fclean re