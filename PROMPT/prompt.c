#include "prompt.h"

char	*get_input()
{
	char	temp[128];
	char	*command;
	char	buf;
	int		ret;
	int		len;

	len = 0;
	while (TRUE)
	{
		ret = read(0, &buf, 1);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break;
		if (buf == '\n')
			break;
		temp[len++] = buf;
	}
	temp[len] = 0;
	if (!(command = ft_strdup(temp)))
		return (NULL);
	return (command);
}

char	*prompt(char *path)
{
	char *command;

	ft_write(1, path);
	if (!(command = get_input()))
		return (NULL);
	return (command);
}
