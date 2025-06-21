/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:33:28 by szakarya          #+#    #+#             */
/*   Updated: 2025/06/12 21:33:32 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	ft_error(void)
{
	if (errno == 0)
		errno = EIO;
	perror("\033[1;31mError\n");
	exit(1);
}

void	check_file(char *file_line)
{
	if (ft_strncmp(file_line + ft_strlen(file_line) - 4, ".ber", 4) != 0)
		ft_error();
}

static void	init_game(t_game *vars)
{
	vars->collect = 0;
	vars->movement = 0;
	vars->mlx_ptr = NULL;
	vars->mlx_win = NULL;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_error();
	check_file(argv[1]);
	game.map = get_map(argv[1], 0, NULL, NULL);
	if (game.map != NULL)
	{
		check_map_valid(&game);
		init_game(&game);
		game.mlx_ptr = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx_ptr,
				game.win_w * 64, game.win_h * 64, "So-Long");
		make_map(&game);
		mlx_hook(game.mlx_win, 17, (1L << 0), ft_exit, &game);
		mlx_key_hook(game.mlx_win, key_hook, &game);
		mlx_string_put(game.mlx_ptr, game.mlx_win, 30, 30, 0xffffff, "Move: 0");
		mlx_loop(game.mlx_ptr);
	}
}
