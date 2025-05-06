/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:03:21 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/06 23:27:21 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

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
