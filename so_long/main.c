#include "include/so_long.h"

int creat_img(int k, t_game *game)
{
	game->x = k;
	printf("k = %d\n", k);
	return (0);
}

int	main()
{
	t_game game;

	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, 1000,800, "Sofi");
	// if (mlx_ptr == NULL)
	// 	return (11);

	mlx_key_hook(game.mlx_win, creat_img, &game);








	mlx_loop(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
	return (0);
}
