/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:03:21 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/13 18:53:12 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	created_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("Error restarting pipe\n");
		return (-1);
	}
	return (0);
}

int	init_pipex(t_pipex *pipex, char **av, char **envp)
{
	if (!av[2] || av[2][0] == '\0')
		return (write(2, "zsh: no such file or directory:", 30), -1);
	if (!av[3] || av[3][0] == '\0')
		return (write(2, "zsh: no such file or directory:", 30), -1);
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->infile = av[1];
	pipex->outfile = av[4];
	pipex->envp = envp;
	pipex->cmd1_args = ft_split(av[2], ' ');
	pipex->cmd2_args = ft_split(av[3], ' ');
	if (!pipex->cmd1_args || !pipex->cmd2_args)
		return (-1);
	pipex->cmd1_path = get_cmd_path(pipex->cmd1_args[0], envp);
	pipex->cmd2_path = get_cmd_path(pipex->cmd2_args[0], envp);
	if (!pipex->cmd1_path || !pipex->cmd2_path)
		cmp_cmds(pipex);
	return (0);
}

int	cmp_cmds(t_pipex *pipex)
{
	int	flag;

	flag = 0;
	if (!pipex->cmd1_path)
	{
		ft_printf("bash: %s command not found\n", pipex->cmd1_args[0]);
		flag++;
	}
	if (!pipex->cmd2_path)
	{
		ft_printf("bash: %s command not found\n", pipex->cmd2_args[0]);
		flag++;
	}
	if (flag > 0)
		return (-1);
	return (0);
}

char	**parse_cmd_args(char *cmds)
{
	char	**args;

	args = ft_split(cmds, ' ');
	if (!args)
		return (NULL);
	return (args);
}
