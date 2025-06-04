#include "include/so_long.h"

char	**get_map(char *map)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (!all_lines || all_lines[0] == '\0')
		ft_error();
	return (ft_split(all_lines, '\n'));
}
