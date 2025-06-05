#include "include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		free(map[i++]);
	free(map);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	put_text(t_game ***v)
{
	char	*text;
	char	*number;
	int		img_w;
	int		img_h;

	number = ft_itoa(++(**v)->movement);
	text = ft_strjoin("Move: ", number);
	(**v)->mlx_img = mlx_xpm_file_to_image(
			(**v)->mlx_ptr, "./textures/Water.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->mlx_img, 0, 0);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->mlx_img, 64, 0);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->mlx_img, 64 * 2, 0);
	mlx_string_put((**v)->mlx_ptr, (**v)->mlx_win, 10, 10, 0xfffffff, text);
	ft_printf("%s\n", number);
	free(text);
	free(number);
}

void	exit_door(t_game ***v)
{
	free_map((**v)->map);
	mlx_destroy_window((**v)->mlx_ptr, (**v)->mlx_win);
	exit(1);
}
