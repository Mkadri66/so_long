# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkadri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 14:12:47 by mkadri            #+#    #+#              #
#    Updated: 2024/03/01 14:46:07 by mkadri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

SRCS = main.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

MLX = minilibx

LIBS = -L$(MLX) -lmlx -lXext -lX11


all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o)

.PHONY: all clean fclean re