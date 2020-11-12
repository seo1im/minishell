#include "lib.h"

int	ft_findstr(char *str, char c)
{
	int i;

	if (!str)
		return (ERROR);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (TRUE);
	return (FALSE);
}