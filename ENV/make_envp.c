#include "env.h"

char **make_envp(char ***env)
{
	char	**envp;
	int		len;
	int		i;

	i = -1;
	while (env[++i])
		;
	len = i;
	if (!(envp = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		if (!(envp[i] = ft_strjoin(env[i], '=')))
			return (NULL);
	envp[i] = 0;
	return (envp);
}