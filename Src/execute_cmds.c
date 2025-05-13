/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:15:59 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/13 18:51:43 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	execute_second_cmds(t_pipex *pipex)
{
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	execve(pipex->cmd2_path, pipex->cmd2_args, pipex->envp);
	exit(EXIT_FAILURE);
}

void	execute_first_cmds(t_pipex *pipex)
{
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	execve(pipex->cmd1_path, pipex->cmd1_args, pipex->envp);
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
		perror("fork 2");
		return ;
	}
	if (pid2 == 0)
		execute_second_cmds(pipex);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
