/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:15 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/09 15:07:36 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		write(2, "Incorrect number of arguments\n", 30);
		return (-1);
	}
	if (init_pipex(&pipex, av, env) == -1)
		return (perror("Pipex did not start\n"), -1);
	if (open_file(&pipex, av) == -1)
		return (perror("Invalid File\n"), -1);
	if (pipe(pipex.pipe_fd) == -1)
		return (perror("Failed to create pipe\n"), -1);
	free_pipex(&pipex);
	return (0);
}
