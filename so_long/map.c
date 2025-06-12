/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:36:11 by szakarya          #+#    #+#             */
/*   Updated: 2025/06/12 21:36:13 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	image_change(t_game **v, char *path)
{
	int		img_w;
	int		img_h;

	(*v)->mlx_img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, path, &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->mlx_img, (*v)->x_p, (*v)->y_p);
	mlx_destroy_image((*v)->mlx_ptr, (*v)->mlx_img);
}

char	**get_map(char *map)
{
	char	*all_lines;
	int		fd;
	char	*tmp;
	char	*line;

	line = get_next_line(fd);
	all_lines = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (line)
	{
		tmp = ft_strjoin(all_lines, line, 0);
		if (!tmp)
			break ;
		free(line);
		all_lines = tmp;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!all_lines || all_lines[0] == '\0')
		ft_error();
	return (ft_split(all_lines, '\n'));
}

void	put_image(t_game ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->mlx_img = mlx_xpm_file_to_image((**v)->mlx_ptr, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx_ptr,
		(**v)->mlx_win, (**v)->mlx_img, x, y);
	mlx_destroy_image((**v)->mlx_ptr, (**v)->mlx_img);
}

void	put_image_to_map(char p, int x1, int y1, t_game **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./textures/Water.xpm");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./textures/Chest.xpm");
		(*v)->collect++;
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./textures/Egg.xpm");
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
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
			x1 += 64;
			game->win_w--;
		}
		game->win_w = w;
		y_map++;
		y1 += 64;
		game->win_h--;
	}
}
