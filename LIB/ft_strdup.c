#include "lib.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	if ((len = ft_strlen(src)) == -1)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strndup(char *src, int len)
{
	char	*dest;
	int		i;

	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	**ft_strsdup(char **src)
{
	char	**dest;
	int		len;
	int		i;

	if ((len = ft_strslen(src)) == -1)
		return (NULL);
	if (!(dest = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		if (!(dest[i] = ft_strdup(src[i])))
			return (NULL);
	dest[i] = 0;
	return (dest);
}
