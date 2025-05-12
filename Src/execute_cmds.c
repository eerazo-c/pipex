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
	if (pid1 < 0)
	{
		perror("fork 1");
		return ;
	}
	if (pid1 == 0)
		execute_first_cmds(pipex);
	pid2 = fork();
	if (pid1 < 0)
	{
		perror ("fork 2");
		return ;
	}
	if (pid2 == 0)
		execute_second_cmds(pipex);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

char	**get_paths(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*cmd_path;
	int		i;

	paths = get_paths(envp); // get_paths debe hacer split del PATH y devolver char**
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (!path)
		{
			free_split(paths);
			return (NULL);
		}
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (!cmd_path)
		{
			free_split(paths);
			return (NULL);
		}
		if (access(cmd_path, X_OK) == 0)
		{
			free_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

