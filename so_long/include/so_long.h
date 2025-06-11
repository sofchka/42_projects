#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_enemy
{
	int		x_e;
	int		y_e;
	int		x;
	int		sleep_for_move;
	int		img;
}	t_enemy;//bonus

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	int		movement;
	char	**map;
	int		collect;
	int		exit;
	int		collected;
	int		chest_sleep;//bonus
	int		chest_img;//bonus
	char	*p[4];//bonus
	t_enemy	e_var;//bonus
}	t_game;

typedef struct s_map
{
	int		c;
	int		p;
	int		e;
	int		x;
	int		y;
}	t_map;

void	ft_error(void);
int		ft_exit(t_game *v);
void	check_file(char *file_line);
char	**get_map(char *map);
void    check_map_valid(t_game *game);
void	check_valid_path(t_game *game);
void	check_elements(t_game **game);
int		get_height(char **map);
void	make_map(t_game *game);
void	ft_error_map(t_game ***g, char *err);
int		key_hook(int keycode, t_game *game);
void	to_right(t_game **v);
void	to_left(t_game **v);
void	to_up(t_game **v);
void	to_down(t_game **v);
void	put_text(t_game ***v);
void	exit_door(t_game ***v);
void	free_map(char **map);
void	image_change(t_game **v, char *path);
int		animation(t_game *vars);//bonus
void	get_position_for_enemy(t_game **v);//bonus
void	put_img(t_game **vars, char *path);//bonus
void	chest_animation(t_game **v);//bonus

#endif