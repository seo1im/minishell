#include "lib.h"

char	**ft_make_strs(char *s1, char *s2)
{
	char **strs;

	if (!(strs = malloc(sizeof(char *) * 3)))
		return (NULL);
	if (!(strs[0] = ft_strdup(s1)))
		return (NULL);
	if (!(strs[1] = ft_strdup(s2)))
		return (NULL);
	strs[2] = 0;
	return (strs);
}