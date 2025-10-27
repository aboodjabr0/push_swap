NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(PUSH_SWAP_DIR)

SRCS = checker.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

PUSH_SWAP_DIR = ..
PUSH_SWAP_SRCS = $(PUSH_SWAP_DIR)/srcs/swap_operations.c \
				$(PUSH_SWAP_DIR)/srcs/push_operations.c \
				$(PUSH_SWAP_DIR)/srcs/rotate_operations.c \
				$(PUSH_SWAP_DIR)/srcs/reverse_rotate_operations.c \
				$(PUSH_SWAP_DIR)/srcs/error_handling.c \
				$(PUSH_SWAP_DIR)/srcs/stack_init.c \
				$(PUSH_SWAP_DIR)/srcs/stack_helpers.c \
				$(PUSH_SWAP_DIR)/srcs/sorting_algo.c \
				$(PUSH_SWAP_DIR)/srcs/sorting_algo_2.c \
				$(PUSH_SWAP_DIR)/srcs/sorting_helpers.c \
				$(PUSH_SWAP_DIR)/srcs/sorting_helpers_2.c

LIBFT = $(PUSH_SWAP_DIR)/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP_SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -s --no-print-directory -C $(PUSH_SWAP_DIR)/libft

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
