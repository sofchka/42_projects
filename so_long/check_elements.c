#include "include/so_long.h"

static char	*ft_err_message(t_map *map)
{
	if (map->c == 0)
		return (
			"\033[1;31m🛑ERROR: element 'C' is missing\033[0m");
	if (map->p == 0)
		return (
			"\033[1;31m🛑ERROR: element 'P' is missing\033[0m");
	if (map->e == 0)
		return (
			"\033[1;31m🛑ERROR: element 'E' is missing\033[0m");
	if (map->p > 1)
		return (
			"\033[1;31m🛑ERROR: there is more then one element 'P'\033[0m");
    if (map->e > 1)
		return (
			"\033[1;31m🛑ERROR: there is more then one element 'E'\033[0m");
	return ("\033[1;31m🛑ERROR: elements missing in the map\033[0m");
}

char	*unknown_element(t_game ***v, char c)
{
	free_map((**v)->map);
	ft_printf("\033[1;31m🛑ERROR: Unknown element %c \033[0m", c);
	exit(1);
}

void	check_elements(t_game **game)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = (*game)->win_h - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*game)->map[map.y][map.x] != '\0')
		{
			if ((*game)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*game)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*game)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*game)->map[map.y][map.x] != '1' &&
				(*game)->map[map.y][map.x] != '0')
				unknown_element(&game, (*game)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1 || map.e > 1)
		ft_error_map(&game, ft_err_message(&map));
}
