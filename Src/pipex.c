/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:15 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/06 23:31:36 by elerazo          ###   ########.fr       */
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
		return (perror("No se inicio\n"), -1);

	free_pipex(&pipex);
	return (0);
}
