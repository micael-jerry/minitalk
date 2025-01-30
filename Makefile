NAME= push_swap
CC= gcc
FLAGS= -Wall -Wextra -Werror
INCLUDE= ./include

SRC_DIR=./src
SRC= ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c \
	ft_utils.c list_int_util.c index_util.c sort_util.c \
	list_int.c ft_params_validator.c ft_sort.c ft_sort_chunk.c main.c \
	ft_test.c

OBJ_DIR= ./obj
OBJ= $(SRC:.c=.o)

LIBFT_PRINTF_DIR= ./ft_printf
LIBFT_PRINTF= libftprintf.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

$(NAME): $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) $(addprefix $(OBJ_DIR)/, $(OBJ))
	$(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) -o $(NAME)
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
