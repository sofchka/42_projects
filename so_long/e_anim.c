#include "include/so_long.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	get_position_for_enemy(t_game **v)
{
	int			y;
	int			x;

	y = 1;
	(*v)->win_h = get_height((*v)->map);
	while (y < (*v)->win_h - 1)
	{
		x = 1;
		while ((*v)->map[y][x] != '\0' && x < (*v)->win_w - 1)
		{
			if ((*v)->map[y][x] == '0' && ((*v)->map[y + 1][x] == '0' ||
			(*v)->map[y - 1][x] == '0' || (*v)->map[y][x + 1] == '0' ||
			(*v)->map[y][x - 1] == '0'))
			{
				(*v)->e_var.x_e = x;
				(*v)->e_var.y_e = y;
				(*v)->e_var.x = 1;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	open_exit(t_game **v)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*v)->map);
	while (y != height)
	{
		x = 0;
		while ((*v)->map[y][x] != '\0')
		{
			if ((*v)->map[y][x] == 'E')
			{
				(*v)->mlx_img = mlx_xpm_file_to_image((*v)->mlx_ptr,
						"./textures/Egg_red.xpm", &img_w, &img_h);
				mlx_put_image_to_window((*v)->mlx_ptr,
					(*v)->mlx_win, (*v)->mlx_img, x * 64, y * 64);
				mlx_destroy_image((*v)->mlx_ptr, (*v)->mlx_img);
			}
			x++;
		}
		y++;
	}
}

void	put_img(t_game **vars, char *path)
{
	int		img_w;
	int		img_h;

	(*vars)->mlx_img = mlx_xpm_file_to_image(
			(*vars)->mlx_ptr, path, &img_w, &img_h);
	mlx_put_image_to_window(
		(*vars)->mlx_ptr, (*vars)->mlx_win, (*vars)->mlx_img, 
		(*vars)->e_var.x_e * 64, (*vars)->e_var.y_e * 64);
	mlx_destroy_image((*vars)->mlx_ptr, (*vars)->mlx_img);
}

void	move_enemy(t_game **v, int x_e, int y_e)
{
	if (ft_abs((*v)->x_p / 64 - x_e) > ft_abs((*v)->y_p / 64 - y_e))
	{
		if ((*v)->x_p / 64 > x_e && (*v)->map[y_e][x_e + 1] != '1')
			(*v)->e_var.x_e++;
		else if ((*v)->x_p / 64 < x_e && (*v)->map[y_e][x_e - 1] != '1')
			(*v)->e_var.x_e--;
		else if ((*v)->y_p / 64 > y_e && (*v)->map[y_e + 1][x_e] != '1')
			(*v)->e_var.y_e++;
		else if ((*v)->y_p / 64 < y_e && (*v)->map[y_e - 1][x_e] != '1')
			(*v)->e_var.y_e--;
	}
	else
	{
		if ((*v)->y_p / 64 > y_e && (*v)->map[y_e + 1][x_e] != '1')
			(*v)->e_var.y_e++;
		else if ((*v)->y_p / 64 < y_e && (*v)->map[y_e - 1][x_e] != '1')
			(*v)->e_var.y_e--;
		else if ((*v)->x_p / 64 > x_e && (*v)->map[y_e][x_e + 1] != '1')
			(*v)->e_var.x_e++;
		else if ((*v)->x_p / 64 < x_e && (*v)->map[y_e][x_e - 1] != '1')
			(*v)->e_var.x_e--;
	}
	if ((*v)->e_var.x_e < x_e || (*v)->e_var.y_e > y_e)
		put_img(v, "./textures/cow2.xpm");
	else
		put_img(v, "./textures/cow.xpm");
}

void	map_repair(t_game **var, int x, int y)
{
	if ((*var)->map[y][x] == 'O')
		put_img(var, "./textures/Chest2.xpm");
	else if ((*var)->map[y][x] == 'C')
		put_img(var, "./textures/Chest.xpm");
	else if ((*var)->map[y][x] == 'E' && (*var)->collect <= 0)
		put_img(var, "./textures/Egg_red.xpm");
	else if ((*var)->map[y][x] == 'E')
		put_img(var, "./textures/Egg.xpm");
	else
		put_img(var, "./textures/Grass.xpm");
}

int animation(t_game *vars)
{
	if (vars->e_var.x == 1)
	{
		put_img(&vars, "./textures/cow.xpm");
		if ((vars->e_var.y_e == vars->y_p / 64)
			&& (vars->e_var.x_e == vars->x_p / 64))
		{
			free_map(vars->map);
			write(1, "You Lost :)\n", 12);
			exit(0);
		}
		if (vars->e_var.sleep_for_move-- <= 0)
		{
			map_repair(&vars, vars->e_var.x_e, vars->e_var.y_e);
			move_enemy(&vars, vars->e_var.x_e, vars->e_var.y_e);
			vars->e_var.sleep_for_move = 30;
		}
	}
	if (vars->collect <= 0)
		open_exit(&vars);
	return (0);
}