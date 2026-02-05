NAME = push_swap

SRC = push_swap.c\
	a_ops.c\
	b_ops.c\
	adaptiv.c\
	simple.c\
	medium.c\
	complex.c\
	bench.c\
	bench_utils.c\
	push_swap_utils_1.c\
	joind_ops.c\
	push_swap_utils_2.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
.PHONY: all clean fclean re
