# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkadri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 14:12:47 by mkadri            #+#    #+#              #
#    Updated: 2024/03/04 18:48:05 by mkadri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    CFLAGS += -Imlx -I/usr/X11/include
    LDFLAGS += -L/usr/X11/lib -lX11 -lXext
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

