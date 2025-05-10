/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:03:21 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/11 01:23:59 by elerazo          ###   ########.fr       */
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
	pipex->infile = av[1];
	pipex->outfile = av[4];
	pipex->envp = envp;
	pipex->cmd1_args = ft_split(av[2], ' ');
	pipex->cmd2_args = ft_split(av[3], ' ');
	if (!pipex->cmd1_args || !pipex->cmd2_args)
		return (-1);
	return (0);
}

char	**parse_cmd_args(char *cmds)
{
	char	**args;

	args = ft_split(cmds, ' ');
	if (args)
		return (NULL);
	return (args);
}
