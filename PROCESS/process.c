#include "process.h"
// https://github.com/olehermanse/mini-shell

static int	cmp(char **argv, int i)
{
	if (!ft_strcmp(argv[i], ">>") ||
		!ft_strcmp(argv[i], "<") ||
		!ft_strcmp(argv[i], ">"))
		return (TRUE);
	return (FALSE);
}

int	check_redirection(char **argv, int **fd)
{
	int len;
	int	descriptor;

	len = ft_strslen(argv);
	if (cmp(argv, len - 1))
	{
		ft_write_n(1, "syntax error near unexpected token `newline\'");
		return (STATUS_FAIL);
	}
	if (len > 2)
	{
		if (*fd == NULL && cmp(argv, len - 2))
			*fd = malloc(sizeof(int) * 2);
		if (!ft_strcmp(argv[len - 2], ">>"))
		{
			descriptor = open(argv[len - 1], O_WRONLY | O_CREAT | O_APPEND, 0755);
			(*fd)[1] = descriptor;
		}
		if (!ft_strcmp(argv[len - 2], ">"))
		{
			descriptor = open(argv[len - 1],  O_WRONLY | O_CREAT, 0755);
			(*fd)[1] = descriptor;
		}
		if (!ft_strcmp(argv[len - 2], "<"))
		{
			descriptor = open(argv[len - 1], O_RDONLY);
			(*fd)[0] = descriptor;
		}
	}
	return (STATUS_SUCCESS);
}

int		work_program(char *cmd, int *fd, char ****env, int is_piped)
{
	char	**argv;
	int		count;
	int		status;
	
	if (!(count = parsing(&argv, cmd, ' ')) < 0)
		ft_exit("Malloc Error", 1);
	if (count == 0)
		status = STATUS_SUCCESS;
	else
	{
		if (check_redirection(argv, &fd) == STATUS_FAIL)
			return (STATUS_FAIL);
		status = internal_program(argv, fd, env);
	}
	!is_piped && fd != NULL ? free(fd) : 0;
	ft_double_free(argv);

	return (status);
}

int		piped_process(char **cmds, int count, char ****env)
{
	int		*fd;
	int		pipe_fd[2];
	int		i;

	if (!(fd = malloc(sizeof(int) * 2)))
		ft_exit("Malloc Error", 1);
	pipe_fd[0] = 0;
	pipe_fd[1] = 0;
	i = -1;
	while (++i < count - 1)
	{
		fd[0] = pipe_fd[0];
		pipe(pipe_fd);
		fd[1] = pipe_fd[1];
		work_program(cmds[i], fd, env, TRUE);
		if (i > 0)
			close(fd[0]);
		close(fd[1]);
	}
	fd[0] = pipe_fd[0];
	fd[1] = 1;
	work_program(cmds[i], fd, env, TRUE);
	close(fd[0]);
	return (STATUS_SUCCESS);
}

int		process(char *command, char ****env)
{
	char	**cmds;
	int		status;
	int		count;
	int		i;

	if ((count = parsing(&cmds, command, '|')) < 0)
		ft_exit("Malloc Error", 1);
	if (count == 0)
		status = STATUS_SUCCESS;
	else if (count == 1)
		status = work_program(cmds[0], NULL, env, FALSE);
	else 
		status = piped_process(cmds, count, env);
	ft_double_free(cmds);
	return (status);
}
