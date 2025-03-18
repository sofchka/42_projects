#include "get_next_line.h"

static void	*clean_storage(char *storage)
{
	if (storage)
		free(storage);
	return (NULL);
}

static char	*keep_storage(char *storage)
{
	char	*res;
	char	*line;

	line = ft_strchr(storage, '\n');
	if (!line)
		return (clean_storage(storage));
	res = ft_strdup(line + 1);
	clean_storage(storage);
	return (res);
}

static char	*extract_line(char *storage)
{
	char	*line;

	if (!storage || !*storage)
		return (NULL);
	line = ft_strchr(storage, '\n');
	if (!line)
		return (ft_substr(storage, 0, ft_strlen(storage)));
	return (ft_substr(storage, 0, line - storage + 1));
}

static char	*read_file(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_storage;

	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		new_storage = ft_strjoin(storage, buffer);
		free(storage);
		storage = new_storage;
		if (!storage)
			return (NULL);
	}
	if (bytes_read < 0)
		return (clean_storage(storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	storage = read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
		return (storage = clean_storage(storage));
	storage = keep_storage(storage);
	return (line);
}
