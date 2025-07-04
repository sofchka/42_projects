/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:36:23 by szakarya          #+#    #+#             */
/*   Updated: 2025/06/12 21:36:28 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_exit(t_game *v)
{
	free_map(v->map);
	mlx_destroy_window(v->mlx_ptr, v->mlx_win);
	mlx_destroy_display(v->mlx_ptr);
	free(v->mlx_ptr);
	exit(1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 100 || keycode == 65363)
		to_right(&game);
	else if (keycode == 97 || keycode == 65361)
		to_left(&game);
	else if (keycode == 119 || keycode == 65362)
		to_up(&game);
	else if (keycode == 115 || keycode == 65364)
		to_down(&game);
	else if (keycode == 65307)
		ft_exit(game);
	return (0);
}

void	put_text(t_game ***v)
{
	ft_putnbr(++(**v)->movement);
}
