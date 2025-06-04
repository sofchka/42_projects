#include "include/so_long.h"

static void	collected(t_game ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collect--;
	(**v)->map[((**v)->y_p / 64)][((**v)->x_p / 64)] = '0';
	(**v)->mlx_img = mlx_xpm_file_to_image(
			(**v)->mlx_ptr, "./textures/Grass.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->mlx_img, (**v)->x_p, (**v)->y_p);
}

void	to_left(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./textures/Grass.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] != '1')
	{
		(*v)->x_p -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/left.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
}

void	to_right(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./textures/Grass.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] != '1')
	{
		(*v)->x_p += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/right.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
}

void	to_up(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./textures/Grass.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/back.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
}

void	to_down(t_game **v)
{
	int		img_w;
	int		img_h;

	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./textures/Grass.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] != '1')
	{
		(*v)->y_p += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
		collected(&v);
	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/front.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
}