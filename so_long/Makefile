NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -Wall -Wextra -Werror -g -I/opt/X11/include

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -lmlx -Lmlx -lXext -lX11 -lm -lz
# MLX_FLAGS = -lmlx -Lmlx -L/opt/X11/lib -lXext -lX11 -lm -lz

LIBFT_PATH = libft/

FT_PRINTF_PATH = ft_printf/

GNL_PATH = get_next_line/

LIBFT_LIB = $(LIBFT_PATH)libft.a

FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

CFILES = main.c so_long_func.c check_file.c move.c map.c check_map.c utils.c check_elements.c

GNL_FILES = $(GNL_PATH)get_next_line.c $(GNL_PATH)get_next_line_utils.c

OBJECTS = $(CFILES:.c=.o) $(GNL_FILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all
	@make -C $(FT_PRINTF_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -Imlx $(OBJECTS) $(MLX_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(MLX_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	make -C $(FT_PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

#norm:
#	norminette libft main.c
#initializer.c key_hook.c map.c move.c validate_input.c place_images.c main.c so_long.h victory.c helpers.c

.PHONY: all clean fclean re #norm
