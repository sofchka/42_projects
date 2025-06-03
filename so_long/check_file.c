#include "include/so_long.h"

void	ft_error()
{
	write(1, "a12", 1);
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}

void	check_file(char *file_line)
{
	if (ft_strncmp(file_line + ft_strlen(file_line) - 4, ".ber", 4) != 0)
		ft_error();
}
