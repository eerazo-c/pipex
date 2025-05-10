/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:04:54 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/11 01:27:05 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

//# <biblioteca.h>
# include <unistd.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include "../library/printf/ft_printf.h"
# include "../library/libft/libft.h"

//structura
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**envp;
	char	**cmd1_args;
	char	**cmd2_args;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
}				t_pipex;

//prototipo de funciones
char	**get_path(char *envp);
char	**parse_cmd_args(char *cmds);
char	*get_cmd_path(char *cmd, char **envp);
int		init_pipex(t_pipex *pipex, char **av, char **envp);
int		open_file(t_pipex *pipex, char **av);
int		created_pipex(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);
void	free_matriz(char **av);
void	execute_cmds(t_pipex *pipex);
void	execute_first_cmds(t_pipex *pipex);
void	execute_second_cmds(t_pipex *pipex);

#endif
