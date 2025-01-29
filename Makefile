NAME = libftprintf.a
CC = gcc
PY = python3
FLAGS = -Wall -Wextra -Werror
INCLUDE = ./include

SRC_DIR = ./src
SRC = ft_print_chr.c ft_print_str.c ft_print_pointer.c ft_print_nbr.c ft_print_u_nbr.c ft_print_hex.c ft_printf.c

OBJ_DIR = ./obj
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(LIBFT_DIR)/$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(addprefix $(OBJ_DIR)/,$(OBJ))
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar -rc $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ))

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re test
