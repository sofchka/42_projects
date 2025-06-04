#include "include/so_long.h"

static void	init_game(t_game *vars)
{
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	// vars->e_vars.sign = 1;
	// vars->e_vars.x = 0;
	// vars->e_vars.sleep = 5;
	// vars->e_vars.sleep_for_move = 60;
	// vars->e_vars.path_to_move = 0;
}

int	main(int argc, char *argv[])
{
	t_game game;

	if (argc <= 1)
		ft_error();
	check_file(argv[1]);
	game.map = get_map(argv[1]);
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
		mlx_string_put(game.mlx_ptr, game.mlx_win, 10, 10, 0xffffff, "Move: 0");
		// mlx_loop_hook(game.mlx_ptr, animation, &game);
		mlx_loop(game.mlx_ptr);
		mlx_destroy_window(game.mlx_ptr, game.mlx_win);//test
		mlx_destroy_display(game.mlx_ptr);//test
	}
	return (0);
}
