#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

# define ESC 65307

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	int		movement;
	char	**map;
	int		collect;
}	t_game;

typedef struct s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy;

typedef struct s_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map;

void	ft_error();
void	check_file(char *file_line);
char	**get_map(char *map);
void    check_map_valid(t_game *game);
void	check_elements(t_game **game);
int		get_height(char **map);
void	make_map(t_game *game);

#endif
