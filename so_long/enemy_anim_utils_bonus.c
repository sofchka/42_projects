/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:35:19 by szakarya          #+#    #+#             */
/*   Updated: 2025/06/12 21:35:30 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

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

void	chest_anim(t_game ***v, int height)
{
	int		y;
	int		x;
	int		img_w;
	int		img_h;

	y = 0;
	while (y != height)
	{
		x = 0;
		while ((**v)->map[y][x] != '\0')
		{
			if ((**v)->map[y][x] == 'C' &&
			!(x == (**v)->x_p / 64 && y == (**v)->y_p / 64)
			&& !((**v)->e_var.y_e == y && (**v)->e_var.x_e == x))
			{
				(**v)->mlx_img = mlx_xpm_file_to_image((**v)->mlx_ptr,
						(**v)->p[(**v)->chest_img], &img_w, &img_h);
				mlx_put_image_to_window((**v)->mlx_ptr,
					(**v)->mlx_win, (**v)->mlx_img, x * 64, y * 64);
				mlx_destroy_image((**v)->mlx_ptr, (**v)->mlx_img);
			}
			x++;
		}
		y++;
	}
}

void	chest_animation(t_game **v)
{
	chest_anim(&v, get_height((*v)->map));
	if ((*v)->chest_img == 3)
		(*v)->chest_img = 0;
	else
		(*v)->chest_img++;
	(*v)->chest_sleep = 25;
}
