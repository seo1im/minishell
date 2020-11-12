#include "env.h"

static int	update(char ****env, int idx, char *value)
{
	ft_single_free((*env)[idx][VALUE]);
	(*env)[idx][VALUE] = ft_strdup(value);
	return (SUCCESS);
}

static int	add(char ****env, char **k_v)
{
	char	***old;
	char	***new;
	int		len;
	int		i;

	old = *env;
	i = -1;
	while (old[++i])
		;
	len = i;
	if (!(new = malloc(sizeof(char **) * (len + 2))))
		return (ERROR);
	i = -1;
	while(old[++i])
		if (!(new[i] = ft_strsdup(old[i])))
			return (ERROR);
	if (!(new[i] = ft_strsdup(k_v)))
		return (ERROR);
	ft_triple_free(old);
	new[++i] = 0;
	*env = new;
	return (SUCCESS);
}

int			update_env(char ****env, char **k_v)
{
	int idx;

	if ((idx = get_index(*env, k_v[KEY])) == -1)
		add(env, k_v);
	else
		update(env, idx, k_v[VALUE]);	
}