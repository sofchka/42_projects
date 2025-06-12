/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:34:21 by szakarya          #+#    #+#             */
/*   Updated: 2025/06/12 21:34:23 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	flood_fill(char **map, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->win_h || x < 0 || x >= game->win_w)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	if (map[y][x] == 'C')
		game->collected++;
	if (map[y][x] == 'E')
		game->exit = 1;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, game);
	flood_fill(map, y - 1, x, game);
	flood_fill(map, y, x + 1, game);
	flood_fill(map, y, x - 1, game);
	return (1);
}

char	**copy_map(char **map)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	if (!new_map)
		return (NULL);
	while (j < i)
	{
		new_map[j] = ft_strdup(map[j]);
		if (!new_map[j])
		{
			while (--j >= 0)
				free(new_map[j]);
			free(new_map);
			return (NULL);
		}
		j++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	check_valid_path(t_game *game)
{
	char	**copy;

	copy = copy_map(game->map);
	game->collected = 0;
	game->exit = 0;
	game->win_w = strlen(game->map[0]);
	flood_fill(copy, game->y_p, game->x_p, game);
	if (game->collected != game->collect || !game->exit)
	{
		free_map(copy);
		free_map(game->map);
		perror("\033[1;31mError\nNo valid path to END\n");
		exit(1);
	}
	free_map(copy);
}
