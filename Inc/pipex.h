/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:04:54 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/06 23:29:09 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

//# <biblioteca.h>
# include <unistd.h>
# include <limits.h>
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
	char	**envp;
}				t_pipex;

//prototipo de funciones
int	init_pipex(t_pipex *pipex, char **av, char **envp);
void	free_pipex(t_pipex *pipex);
void	free_matriz(char **av);

#endif
