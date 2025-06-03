#include "include/so_long.h"

// int	key_hook(int keycode, t_vars *vars)
// {
// 	int	x;

// 	if (keycode == 2 || keycode == 124)
// 		to_right(&vars);
// 	else if (keycode == 0 || keycode == 123)
// 		to_left(&vars);
// 	else if (keycode == 13 || keycode == 126)
// 		to_up(&vars);
// 	else if (keycode == 1 || keycode == 125)
// 		to_down(&vars);
// 	else if (keycode == 53)
// 	{
// 		x = 0;
// 		while (vars->map[x])
// 		{
// 			free(vars->map[x]);
// 			x++;
// 		}
// 		free(vars->map);
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(1);
// 	}
// 	return (0);
// }

// int	ft_exit(t_vars *v)
// {
// 	int	x;

// 	x = 0;
// 	while (v->map[x])
// 	{
// 		free(v->map[x]);
// 		x++;
// 	}
// 	free(v->map);
// 	mlx_destroy_window(v->mlx, v->win);
// 	exit(1);
// 	return (0);
// }





void	put_image(t_game ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->mlx_img = mlx_xpm_file_to_image((**v)->mlx_ptr, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx_ptr, (**v)->mlx_win, (**v)->mlx_img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_game **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./textures/Water.xpm");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./textures/Grass.xpm");
		put_image(&v, x1, y1, "./textures/Chest.xpm");
		(*v)->collect++;
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./textures/Egg.xpm");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		put_image(&v, x1, y1, "./textures/Grass.xpm");
		put_image(&v, x1, y1, "./textures/front.xpm");
	}
	else
		put_image(&v, x1, y1, "./textures/Grass.xpm");
}

void	make_map(t_game *game)
{
	int	y1;
	int	y_map;
	int	w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	w = game->win_w;
	while (game->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (game->win_w > 0)
		{
			put_image_to_map(game->map[y_map][x_map], x1, y1, &game);
			x_map++;
			x1 += 32;
			game->win_w--;
		}
		game->win_w = w;
		y_map++;
		y1 += 32;
		game->win_h--;
	}
}
