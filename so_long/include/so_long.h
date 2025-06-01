#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

# define ESC 65307
# define MK_ERR 1
# define HEIGHT 600
# define WIDTH 1200

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

#endif
