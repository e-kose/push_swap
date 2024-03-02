NAME = push_swap

SRCS = main.c checker.c push_swap_utils.c free.c \
		push.c rotate.c reverse_rotate.c swap.c \
		sort.c push_swap_utils2.c sort_utils.c
OBJS = ${SRCS:.c=.o}
CC = gcc
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m"
	@make -C ./libft bonus
	@$(CC) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	@echo "\033[0;34m"
	@make clean -C ./libft
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[33m"
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING!\n"

re: fclean all

.PHONY: all clean fclean re
