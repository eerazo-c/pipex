//header
#include "pipex.h"

void	execute_second_cmds(t_pipex *pipex)
{
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	execve(pipex->cmd2_path, pipex->cmd2_args, pipex->envp);
	perror("Error al ejecutar cmd2");
	exit(EXIT_FAILURE);
}

void	execute_first_cmds(t_pipex *pipex)
{
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	execve(pipex->cmd1_path, pipex->cmd1_args, pipex->envp);
	perror("Error al ejecutar cmd1");
	exit(EXIT_FAILURE);
}

void	execute_cmds(t_pipex *pipex)
{
	pid_t	pid1;
	pid_t	pid2;	

	pid1 = fork();
	if (pid1 == 0)
		execute_first_cmds(pipex);
	waitpid(pid1, NULL, 0);
	pid2 = fork();
	if (pid2 == 0)
		execute_second_cmds(pipex);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pid2, NULL, 0);
}

char	**get_paths(char **envp)
{
	char	*path_line;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	path_line = envp[i] + 5;
	return (ft_split(path_line, ':'));
}

char	*get_cmd_path(char	*cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
		return (cmd);
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(paths);
			return (full_path);
		}
		free (full_path);
		i++;
	}
	free(paths);
	return (NULL);
}
