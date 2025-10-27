GREEN   = \033[32m
BOLD    = \033[1m
BLUE    = \033[96m

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS_DIR = srcs

Srcs = $(SRCS_DIR)/swap_operations.c \
		$(SRCS_DIR)/push_operations.c \
		$(SRCS_DIR)/rotate_operations.c \
		$(SRCS_DIR)/reverse_rotate_operations.c \
		$(SRCS_DIR)/error_handling.c \
		$(SRCS_DIR)/stack_init.c \
		$(SRCS_DIR)/stack_helpers.c \
		$(SRCS_DIR)/sorting_algo.c \
		$(SRCS_DIR)/sorting_algo_2.c \
		$(SRCS_DIR)/sorting_helpers.c \
		$(SRCS_DIR)/sorting_helpers_2.c \
		$(SRCS_DIR)/main.c 

OBJS = $(Srcs:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo " Compiled with $(GREEN)$(BOLD)$(CFLAGS)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)--------------------------"
	@echo "  $(NAME) = READY TO USE  "
	@echo "$(BLUE)--------------------------"
$(LIBFT):
	@echo "$(GREEN) Getting libft and ft_printf ready"
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)

bonus:
	@cd bonus && make -s --no-print-directory
	@echo "$(GREEN) Getting checker ready"
	@echo "$(BLUE)--------------------------"
	@echo " checker is ready      "
	@echo "$(BLUE)--------------------------"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo "$(BLUE) object files deleted ✅"
fclean: clean
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) fclean
	@cd bonus && $(MAKE) -s --no-print-directory fclean
	@rm -f $(NAME)
	@echo "$(BLUE) executable file deleted ✅"
	@echo "$(BLUE) $(BOLD)$(NAME) is clean ✅"
re: fclean all

.PHONY: all clean fclean re
