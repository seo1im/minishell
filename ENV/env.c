#include "env.h"

char		**kv_parse(char *raw_k_v)
{
	char	**k_v;
	int		i;

	if (!(k_v = malloc(sizeof(char *) * 3)))
		return (NULL);
	i = -1;
	while (raw_k_v[++i])
		if (raw_k_v[i] == '=')
			break;
	if (!(k_v[0] = ft_strndup(raw_k_v, i)))
		return (NULL);
	if (!(k_v[1] = ft_strdup(raw_k_v + i + 1)))
		return (NULL);
	k_v[2] = 0;
	return (k_v);
}

int			get_index(char ***env, char *key)
{
	int i;

	i = -1;
	while (env[++i])
	{
		if (ft_strcmp(env[i][KEY], key) == 0)
			return (i);
	}
	return (-1);
}

int			init_env(char ****env_address, char *envp[])
{
	char	***env;
	int		len;
	int		i;

	if ((len = ft_strslen(envp)) == -1)
		return (ERROR);
	if (!(env = malloc(sizeof(char **) * (len + 1))))
		return (ERROR);
	i = -1;
	while (++i < len)
		if (!(env[i] = kv_parse(envp[i])))
			return (ERROR);
	env[i] = 0;
	*env_address = env;
}

char		*get_env(char ***env, char *key)
{
	int idx;
	
	if ((idx = get_index(env, key)) == -1)
		return (ft_strdup(""));
	return (ft_strdup(env[idx][VALUE]));
}