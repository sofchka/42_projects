NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -lmlx -Lmlx -lXext -lX11 -lm -lz

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = main.c
#initializer.c\
		# key_hook.c\
		# map.c\
		# move.c\
		# validate_input.c\
		# place_images.c\
		# main.c\
		# victory.c\
		# check_valid_path.c\
		# helpers.c\

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -Imlx $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

#norm:
#	norminette libft main.c
#initializer.c key_hook.c map.c move.c validate_input.c place_images.c main.c so_long.h victory.c helpers.c

.PHONY: all clean fclean re #norm
