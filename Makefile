NAME = get_next_line
CC = gcc
BUFFER_SIZE ?= 5
CFLAGS = -Wall -Wextra -Werror -I. -D BUFFER_SIZE=$(BUFFER_SIZE)
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
RM = -rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re