NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lpthread -lm

SRC = auxft.c events.c init_fractal.c main.c math_utils.c render_fractal.c

OBJ = $(SRC:.c=.o)

RM = rm -f

INCLUDE = -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
		$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)

&.o: %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re