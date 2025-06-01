#include "include/so_long.h"

int	key_hook(int key, t_game *vars)
{
	int	x;

	if (key == 2 || key == 124)
		to_right(&vars);
	else if (key == 0 || key == 123)
		to_left(&vars);
	else if (key == 13 || key == 126)
		to_up(&vars);
	else if (key == 1 || key == 125)
		to_down(&vars);
	else if (key == 53)
	{
		x = 0;
		while (vars->map[x])
		{
			free(vars->map[x]);
			x++;
		}
		free(vars->map);
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
		exit(1);
	}
	return (0);
}
