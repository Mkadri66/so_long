# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkadri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 16:05:49 by mkadri            #+#    #+#              #
#    Updated: 2024/03/25 14:25:25 by mkadri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c ./libs/*c get_next_line/*c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./mlx -I/usr/X11/include

LDFLAGS = -Lmlx -lmlx -L./get_next_line -L/usr/X11/lib -lX11 -lXext

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    CFLAGS += -Imlx_linux -I/usr/X11/include
    LDFLAGS += -L/usr/X11/lib -lX11 -lXext -lm
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
