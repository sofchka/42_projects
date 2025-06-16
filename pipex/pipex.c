#include "pipex.h"

static void	child1(t_vars *vars, char **argv, char **envp)
{
	vars->infile = open(argv[1], O_RDONLY);
	if (vars->infile == -1)
		ft_exit("\033[1;31mError:\n");
	vars->path = find_cmd(argv[2], envp, 0, NULL);
	if (!vars->path)
		ft_exit("\033[1;31mCommand not found");
	vars->cmd = ft_split(argv[2], ' ');
	if (!vars->cmd)
	{
		free(vars->path);
		ft_exit("\033[1;31mError(malloc):\n");
	}
	dup2(vars->infile, 0);
	dup2(vars->pfd[1], 1);
	close(vars->pfd[0]);
	close(vars->infile);
	close(vars->pfd[1]);
	if (execve(vars->path, vars->cmd, envp) == -1)
	{
		ft(vars->cmd, vars->path);
		ft_exit("\033[1;31mexecve cmd1");
	}
}

static void	child2(t_vars *vars, char **argv, char **envp)
{
	vars->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->outfile == -1)
		ft_exit("\033[1;31mError:\n");
	vars->path = find_cmd(argv[3], envp, 0, NULL);
	if (!vars->path)
		ft_exit("\033[1;31mCommand not found");
	vars->cmd = ft_split(argv[3], ' ');
	if (!vars->cmd)
	{
		free(vars->path);
		ft_exit("\033[1;31mError(malloc):\n");
	}
	dup2(vars->pfd[0], 0);
	dup2(vars->outfile, 1);
	close(vars->pfd[0]);
	close(vars->pfd[1]);
	close(vars->outfile);
	if (execve(vars->path, vars->cmd, envp) == -1)
	{
		ft(vars->cmd, vars->path);
		ft_exit("\033[1;31mexecve cmd2");
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_vars	var;

	if (argc != 5)
		ft_exit("\033[1;31m./pipex file1 cmd1 cmd2 file2");
	if (pipe(var.pfd) == -1)
		ft_exit("\033[1;31mError(pipe):\n");
	var.pid1 = fork();
	if (var.pid1 < 0)
		ft_exit("\033[1;31mError(fork):\n");
	else if (var.pid1 == 0)
		child1(&var, argv, envp);
	var.pid2 = fork();
	if (var.pid2 < 0)
		ft_exit("\033[1;31mError(fork):\n");
	else if (var.pid2 == 0)
		child2(&var, argv, envp);
	close(var.pfd[0]);
	close(var.pfd[1]);
	waitpid(var.pid2, NULL, 0);
	waitpid(var.pid1, NULL, 0);
	return (0);
}
