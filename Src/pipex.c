/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:15 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/05 22:05:22 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac != 5)
		write(2, "Incorrect number of arguments\n", 30);
	
	ft_init_pipex(&pipex);
}
