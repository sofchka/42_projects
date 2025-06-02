#include "include/so_long.h"

void	ft_error()
{
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}


int find(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		if (str2[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (find(file_line, ".ber"))
			{
				return ;
			}
		}
		file_line++;
	}
	ft_error();
}