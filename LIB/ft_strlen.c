#include "lib.h"

int ft_strlen(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (ERROR);
	while (str[++i])
		;
	return (i);
}

int ft_strslen(char *strs[])
{
	int i;

	i = -1;
	if (!strs)
		return (ERROR);
	while (strs[++i])
		;
	return (i);
}