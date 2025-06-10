#include "include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static char	*ft_err_message(t_map *map)
{
	if (map->c == 0)
		return ("\033[1;31mError\nElement 'C' is missing\n");
	if (map->p == 0)
		return ("\033[1;31mError\nElement 'P' is missing\n");
	if (map->e == 0)
		return ("\033[1;31mError\nElement 'E' is missing\n");
	if (map->p > 1)
		return ("\033[1;31mError\nThere is more then one element 'P'\n");
	if (map->e > 1)
		return ("\033[1;31mError\nThere is more then one element 'E'\n");
	return ("\033[1;31mError\nElements missing in the map\n");
}

void	check_elements_2(t_game ***game, t_map *map)
{
	while ((*map).y--)
	{
		(*map).x = 0;
		while ((**game)->map[(*map).y][(*map).x] != '\0')
		{
			if ((**game)->map[(*map).y][(*map).x] == 'E')
				(*map).e++;
			else if ((**game)->map[(*map).y][(*map).x] == 'P')
				(*map).p++;
			else if ((**game)->map[(*map).y][(*map).x] == 'C')
				(*map).c++;
			else if ((**game)->map[(*map).y][(*map).x] != '1' &&
				(**game)->map[(*map).y][(*map).x] != '0')
			{
				free_map((**game)->map);
				perror("\033[1;31mError\nUnknown element\n");
				exit(1);
			}
			(*map).x++;
		}
	}
}

void	check_elements(t_game **game)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = (*game)->win_h - 1;
	check_elements_2(&game, &map);
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1 || map.e > 1)
		ft_error_map(&game, ft_err_message(&map));
}