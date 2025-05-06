/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:15 by elerazo-          #+#    #+#             */
/*   Updated: 2025/05/06 19:36:05 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int main(int ac, char **av, char **env)
{
	(void)av;
	(void)env;

	if (ac != 5)
		write(2, "Incorrect number of arguments\n", 30);
	if (access("example.txt", R_OK) != -1)
		ft_printf("I have permission\n");
	else
		ft_printf("I don't have permission");
}
