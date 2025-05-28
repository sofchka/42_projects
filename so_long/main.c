#include "include/so_long.h"

int creat_img(int k, t_game *game)
{
	//if (k == ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game game;

	if (argc <= 1)
	{
		perror("\033[1;31m🛑ERROR \033[0m"); //?
		exit(1);
	}
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
	mlx_key_hook(game.mlx_win, handle_input(), &game);

	mlx_key_hook(game.mlx_win, creat_img, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.mlx_win);
	mlx_destroy_display(game.mlx_ptr);
	return (0);
}