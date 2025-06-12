/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:33:49 by szakarya          #+#    #+#             */
/*   Updated: 2025/06/12 21:33:51 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	collected(t_game ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collect--;
	(**v)->map[((**v)->y_p / 64)][((**v)->x_p / 64)] = 'O';
	(**v)->mlx_img = mlx_xpm_file_to_image(
			(**v)->mlx_ptr, "./textures/Chest2.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->mlx_img, (**v)->x_p, (**v)->y_p);
	mlx_destroy_image((**v)->mlx_ptr, (**v)->mlx_img);
}

void	to_left(t_game **v)
{
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'O')
		image_change(v, "./textures/Chest2.xpm");
	else
		image_change(v, "./textures/Grass.xpm");
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) - 1] != '1')
	{
		if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
			collected(&v);
		(*v)->x_p -= 64;
		put_text(&v);
	}
	image_change(v, "./textures/left.xpm");
}

void	to_right(t_game **v)
{
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'O')
		image_change(v, "./textures/Chest2.xpm");
	else
		image_change(v, "./textures/Grass.xpm");
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64) + 1] != '1')
	{
		if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
			collected(&v);
		(*v)->x_p += 64;
		put_text(&v);
	}
	image_change(v, "./textures/right.xpm");
}

void	to_up(t_game **v)
{
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'O')
		image_change(v, "./textures/Chest2.xpm");
	else
		image_change(v, "./textures/Grass.xpm");
	if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) - 1][((*v)->x_p / 64)] != '1')
	{
		if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
			collected(&v);
		(*v)->y_p -= 64;
		put_text(&v);
	}
	image_change(v, "./textures/back.xpm");
}

void	to_down(t_game **v)
{
	if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'O')
		image_change(v, "./textures/Chest2.xpm");
	else
		image_change(v, "./textures/Grass.xpm");
	if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_p / 64) + 1][((*v)->x_p / 64)] != '1')
	{
		if ((*v)->map[((*v)->y_p / 64)][((*v)->x_p / 64)] == 'C')
			collected(&v);
		(*v)->y_p += 64;
		put_text(&v);
	}
	image_change(v, "./textures/front.xpm");
}
