#include "parsing.h"

static void	init(int checker[3], char c)
{
	checker[COMMA] = c == '\'' ? TRUE : FALSE;
	checker[SLASH] = c == '\\' ? TRUE : FALSE;
	checker[DCOMMA] = c == '\"' ? TRUE : FALSE;
}

static void comma_process(char *command, int checker[3], int i)
{
	if (command[i] == '\'' && !checker[DCOMMA] && !checker[SLASH])
		checker[COMMA] = !checker[COMMA];
	if (command[i] == '\"' && !checker[COMMA] && !checker[SLASH])
		checker[DCOMMA] = !checker[DCOMMA];
}

static int slash_process(char *command, int checker[3], int i)
{
	if (command[i] == '\\')
	{
		checker[SLASH] = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	parsing(char ***cmds, char *command, char c)
{
	*cmds = ft_split(command, c);
	return (ft_strslen(*cmds));
}