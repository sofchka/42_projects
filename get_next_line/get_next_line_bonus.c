/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:34:58 by szakarya          #+#    #+#             */
/*   Updated: 2025/03/19 18:35:07 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*storage[FOPEN_MAX + 1];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_file(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	if (!line)
		return (storage[fd] = clean_storage(storage[fd]));
	storage[fd] = keep_storage(storage[fd]);
	return (line);
}
