#include "env.h"

static int	length(char ***env)
{
	int i;

	i = -1;
	while (env[++i])
		;
	return (i);
}

int			remove_env(char ****env, char *key)
{
	char	***new;
	int		idx;
	int		len;
	int		i;
	int		j;

	if ((idx = get_index(*env, key)) == -1)
		return (0);
	len = length(*env);
	if (!(new = malloc(sizeof(char **) * len)))
		return (ERROR);
	i = -1;
	j = -1;
	while (++i < len)
	{
		if (i == idx)
			continue;
		if (!(new[++j] = ft_strsdup((*env)[i])))
			return (ERROR);
	}
	new[++j] = 0;
	ft_triple_free((*env));
	*env = new;
}