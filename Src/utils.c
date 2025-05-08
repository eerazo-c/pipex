//header
#include "pipex.h"

int	open_file(t_pipex *pipex, char **av)
{
	pipex->infile_fd = open(av[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		return (perror("Fallo al abrir el infile\n"), -1);
	pipex->outfile_fd = open(av[4], O_CREAT | O_WRONLY );
	if (pipex->outfile_fd < 0)
		return (perror("Fallo outfile\n"), -1);
	return (0);
}

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
