NAME_CLIENT= client
NAME_SERVER= server
CC= gcc
FLAGS= -Wall -Wextra -Werror
INCLUDE= ./include

SRC_DIR_CLIENT=./src/client
SRC_CLIENT= client.c
OBJ_DIR_CLIENT= ./obj/client
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)

SRC_DIR_SERVER=./src/server
SRC_SERVER= server.c sig_handler.c error.c
OBJ_DIR_SERVER= ./obj/server
OBJ_SERVER= $(SRC_SERVER:.c=.o)

LIBFT_PRINTF_DIR= ./ft_printf
LIBFT_PRINTF= libftprintf.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

$(OBJ_DIR_CLIENT)/%.o: $(SRC_DIR_CLIENT)/%.c
	mkdir -p $(OBJ_DIR_CLIENT)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(OBJ_DIR_SERVER)/%.o: $(SRC_DIR_SERVER)/%.c
	mkdir -p $(OBJ_DIR_SERVER)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(NAME_CLIENT): $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) $(addprefix $(OBJ_DIR_CLIENT)/, $(OBJ_CLIENT))
	$(CC) $(FLAGS) $(addprefix $(OBJ_DIR_CLIENT)/, $(OBJ_CLIENT)) $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) $(addprefix $(OBJ_DIR_SERVER)/, $(OBJ_SERVER))
	$(CC) $(FLAGS) $(addprefix $(OBJ_DIR_SERVER)/, $(OBJ_SERVER)) $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) -o $(NAME_SERVER)

clean:
	rm -rf $(OBJ_DIR_CLIENT)
	rm -rf $(OBJ_DIR_SERVER)
	make clean -C $(LIBFT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME_CLIENT)
	rm -rf $(NAME_SERVER)
	make fclean -C $(LIBFT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
