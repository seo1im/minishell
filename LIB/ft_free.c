#include "lib.h"

void	ft_single_free(char *data)
{
	free(data);
}

void	ft_double_free(char **data)
{
	int i;

	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}

void	ft_triple_free(char ***data)
{
	int i;
	int j;

	i = -1;
	while (data[++i])
	{
		j = -1;
		while (data[i][++j])
			free(data[i][j]);
		free(data[i]);
	}
	free(data);
}