NAME = so_long

SRCS = main.c ./libs/*c get_next_line/*c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./get_next_line

LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -L./get_next_line 

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
