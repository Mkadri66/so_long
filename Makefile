# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkadri <mkadri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 16:05:49 by mkadri            #+#    #+#              #
#    Updated: 2024/04/15 15:05:41 by mkadri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c $(wildcard ./libs/*.c) $(wildcard get_next_line/*.c) $(wildcard ft_printf/*.c)
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./mlx -I./mlx_linux -I/usr/X11/include -g
LDFLAGS = -Lmlx -lmlx -L./get_next_line -L/usr/X11/lib -lX11 -lXext -lm

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    CFLAGS += -Imlx_linux
    LDFLAGS += -L/usr/X11/lib -lX11 -lXext -lm
endif
ifeq ($(UNAME), Darwin) 
    CFLAGS += -Imlx_mac
    LDFLAGS += -Lmlx -framework OpenGL -framework AppKit
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
