NAME = so_long

CC = cc

# CFLAGS = -Wall -Wextra -Werror -g # for ubuntu
CFLAGS = -Wall -Wextra -Werror -g -I/opt/X11/include # for macos

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

# MLX_FLAGS = -lmlx -Lmlx -lXext -lX11 -lm -lz # for ubuntu
MLX_FLAGS = -lmlx -Lmlx -L/opt/X11/lib -lXext -lX11 -lm -lz #for macos

LIBFT_PATH = libft/

GNL_PATH = get_next_line/

LIBFT_LIB = $(LIBFT_PATH)libft.a

CFILES = main.c so_long_func.c move.c map.c check_map.c check_path.c check_elements.c

CFILES_BONUS = main2.c so_long_func.c move.c map.c check_map.c check_path.c check_elements.c enemy_anim_bonus.c enemy_anim_utils_bonus.c

GNL_FILES = $(GNL_PATH)get_next_line.c $(GNL_PATH)get_next_line_utils.c

OBJECTS = $(CFILES:.c=.o) $(GNL_FILES:.c=.o)

OBJECTS_BONUS = $(CFILES_BONUS:.c=.o) $(GNL_FILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

subsystems:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -Imlx $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

bonus: subsystems $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) -Imlx $(OBJECTS_BONUS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	make -C $(MLX_PATH) fclean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

norm:
	norminette libft get_next_line $(CFILES) enemy_anim_bonus.c enemy_anim_utils_bonus.c main2.c

.PHONY: all clean fclean re norm bonus
