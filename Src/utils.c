//header
#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	free_matriz(pipex->cmd1_args);
	free_matriz(pipex->cmd2_args);
}

void	free_matriz(char **av)
{
	int	i;

	i = 0;
	if(!av)
		return;
	while (av[1])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
