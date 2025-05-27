#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define ESC 65307

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
}	t_game;

#endif
