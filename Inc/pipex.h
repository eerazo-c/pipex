/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:04:54 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/09 14:58:34 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

//# <biblioteca.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../library/printf/ft_printf.h"
# include "../library/libft/libft.h"

//structura
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmd1_args;
	char	**cmd2_args;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	char	**envp;
}				t_pipex;

//prototipo de funciones
int		init_pipex(t_pipex *pipex, char **av, char **envp);
void	free_pipex(t_pipex *pipex);
void	free_matriz(char **av);
int		open_file(t_pipex *pipex, char **av);
int		created_pipex(t_pipex *pipex);
//int		childre_process(f1, cmd1_args);

#endif
