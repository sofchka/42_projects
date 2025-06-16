#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_vars
{
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd;
}	t_vars;

void	ft_exit(char *err);
void	ft(char **str, char *arr);
char	*find_cmd(char *command, char **envp, int i, char *tmp);

#endif
