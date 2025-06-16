#include "pipex.h"

void	ft_exit(char *err)
{
	if (errno == 0)
		errno = EIO;
	perror(err);
	exit(1);
}

int	find_path(char **envp, char ***path)
{
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (!*envp)
		return (0);
	*path = ft_split(*envp + 5, ':');
	if (!*path)
		return (0);
	return (1);
}

char	*find_cmd(char *command, char **envp, int i, char *tmp)
{
	char	**paths;
	char	**cmd;

	if (find_path(envp, &paths) == 0)
		return (NULL);
	while (paths[i])
	{
		cmd = ft_split(command, ' ');
		if (!cmd || !cmd[0])
			return (ft(paths, NULL), NULL);
		tmp = ft_strjoin(paths[i], "/", 0);
		if (!tmp)
			return (ft(paths, NULL), ft(cmd, NULL), NULL);
		if (cmd[0][0] != '/')
			tmp = ft_strjoin(tmp, cmd[0], 1);
		else
			tmp = ft_strjoin(tmp, strrchr(*cmd, '/') + 1, 1); //leak?
		if (!tmp)
			return (ft(paths, NULL), ft(cmd, NULL), NULL);
		if (access(tmp, X_OK) == 0)
			return (ft(paths, NULL), ft(cmd, NULL), tmp);
		ft(cmd, tmp);
		i++;
	}
	return (ft(paths, NULL), NULL);
}

void	ft(char **str, char *arr)
{
	int	i;

	if (arr)
		free(arr);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
