#include "include/so_long.h"

int	handle_input(int key, t_game *game)
{
	if (key == ESC)
	{
		write(1, "Exiting\n", 8);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	write(1, "Key - X\n", 8);
	return (0);
}

int	main()
{
	t_game game;

	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (MK_ERR);
	game.mlx_win = mlx_new_window(game.mlx_ptr, HEIGHT, WIDTH, "MiniGame");
	if (game.mlx_win == NULL)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		return (MK_ERR);
	}
	mlx_key_hook(game.mlx_win, handle_input, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.mlx_win);
	mlx_destroy_display(game.mlx_ptr);
	return (0);
}
