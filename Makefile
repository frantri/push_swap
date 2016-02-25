SRC = maintest.c \
	  operations.c \
	  parsing.c \
	  sort_stack.c \
	  stack.c \
	  stack_op.c \
	  stack_utils.c \
	  utils.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror -lft -L libft $(OBJ) -o $(NAME)

%.o: %.c
	gcc -c -Wall -Werror -Wextra -I . -I ./libft/includes $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re:fclean all

.PHONY: all re fclean clean
