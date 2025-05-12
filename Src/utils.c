/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:30:29 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/13 00:20:48 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_close_fd(t_pipex *pipex)
{
	if (pipex->infile_fd > 0)
		close(pipex->infile_fd);
	if (pipex->outfile_fd > 0)
		close(pipex->outfile_fd);
	if ((pipex->fd)[0] != -1)
		close((pipex->fd)[0]);
	if ((pipex->fd)[1] != -1)
		close((pipex->fd)[1]);
}

int	open_file(t_pipex *pipex, char **av)
{
	pipex->infile_fd = open(av[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		return (perror("Fallo al abrir el infile\n"), -1);
	pipex->outfile_fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		return (perror("Fallo outfile\n"), -1);
	return (0);
}

void	free_split(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_pipex(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->cmd1_args)
		free_matriz(pipex->cmd1_args);
	if (pipex->cmd2_args)
		free_matriz(pipex->cmd2_args);
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
	 if (pipex->infile_fd != -1)
        close(pipex->infile_fd);
    if (pipex->outfile_fd != -1)
        close(pipex->outfile_fd);
	/*ft_close_fd(pipex);
    free_matriz(pipex->cmd1_args);
    free_matriz(pipex->cmd2_args);
    free(pipex->cmd1_path);
    free(pipex->cmd2_path);*/
}

void	free_matriz(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
