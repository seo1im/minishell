#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	int		status;
	int		is_work;
	char	*command;
	char	**cmds;
	int		i;
	char 	***env;

	init_env(&env, envp);
	is_work = TRUE;
	while (is_work)
	{
		if (!(command = prompt("$ ")))
			ft_exit("Malloc problem", 1);
		if (command[0])
		{
			parsing(&cmds, command, ';');
			i = -1;
			while (cmds[++i])
			{
				status = process(command, &env);
				if (status == STATUS_EXIT)
					is_work = FALSE;
			}
		}
		free(command);
	}
}
