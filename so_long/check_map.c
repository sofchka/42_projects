#include "include/so_long.h"

void	ft_error_map(t_game ***g, char *err)
{
	free_map((**g)->map);
	perror(err);
	exit(1);
}

static void	check_rectangular(t_game **game)
{
	int	y;
	int	x;
	int	backup;

	y = 0;
	backup = 0;
	while (y != (*game)->win_h)
	{
		x = 0;
		while ((*game)->map[y][x] != '\0')
			x++;
		y++;
		if (backup != 0)
		{
			if (backup != x)
				ft_error_map(&game,
					"\033[1;31mError\nMap is not rectangular\n");
		}
		else
			backup = x;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_surrounded_by_walls(t_game **game)
{
	int		i;
	char	*err;

	err = "\033[1;31mError\nMap is not surrounded by walls\n";
	if (check_line((*game)->map[0]))
		ft_error_map(&game, err);
	i = (*game)->win_h - 1;
	while (i)
	{
		if ((*game)->map[i][0] != '1' ||
			(*game)->map[i][ft_strlen((*game)->map[i]) - 1] != '1')
			ft_error_map(&game, err);
		i--;
	}
	if (check_line((*game)->map[(*game)->win_h - 1]))
		ft_error_map(&game, err);
}

void	check_map_valid(t_game *game)
{
	game->win_h = get_height(game->map);
	check_rectangular(&game);
	check_surrounded_by_walls(&game);
	check_elements(&game);
	check_valid_path(game);
}