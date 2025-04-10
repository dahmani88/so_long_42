NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = check_map_utils2.c  check_map_utils3.c  check_map_utils.c  checks.c  get_next_line.c  \
	get_next_line_utils.c  so_long.c  utils1.c  utils2.c move_player.c ft_putnbr.c
OBJ = $(SRC:.c=.o)

MLX_FLAGS = -L/path/minilibx-linux -lmlx -lXext -lX11 -lm # Change this to suit your library path :/ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
