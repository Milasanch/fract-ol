NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = auxft.c events.c init_fractal.c main.c math_utils.c render_fractal.c

OBJ = $(SRC : .c = .o)

AR = ar -rcs

RM = rm -f

INCLUDE = -I

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

&.o: %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re