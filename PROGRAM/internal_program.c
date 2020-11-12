#include "internal_program.h"

static int	check(char *exec)
{
	if (!exec[0] || !exec)
		return (NONE);
	else if (!ft_strcmp(exec, "cd"))
		return (CD);
	else if (!ft_strcmp(exec, "pwd"))
		return (PWD);
	else if (!ft_strcmp(exec, "export"))
		return (EXPORT);
	else if (!ft_strcmp(exec, "unset"))
		return (UNSET);
	else if (!ft_strcmp(exec, "env"))
		return (ENV);
	else if (!ft_strcmp(exec, "echo"))
		return (ECHO);
	else if (!ft_strcmp(exec, "exit"))
		return (EXIT);
	else if (!ft_strcmp(exec, "test"))
		return (500);
	return (NONE);
}

static int	unset(char **argv, int *fd, char ****env)
{
	remove_env(env, argv[0]);
}

static int	env_(char **argv, int *fd, char ***env)
{
	char	**envp;
	int		i;
	int		descriptor;

	envp = make_envp(env);
	descriptor = fd == NULL ? 1 : fd[1];
	i = -1;
	while (envp[++i])
		ft_write_n(descriptor, envp[i]);
	return (STATUS_SUCCESS);
}

static int	export(char **args, int *fd, char ****env)
{
	char	**kv;
	int		i;

	if (ft_strslen(args) == 0)
		;//TODO : write fd some env writing

	i = -1;	
	if (fd == NULL)
	{
		while (args[++i])
		{
			kv = kv_parse(args[i]);
			update_env(env, kv);
			free(kv);
		}
	}
	i = -1;
	return (STATUS_SUCCESS);
}

static int	cd(char **argv, int *fd, char ***env)
{
	int result;
	
	if (ft_strslen(argv) > 1)
	{
		ft_write_n(1, "cd : too many arguments");
		return (STATUS_FAIL);
	}
	if (ft_strslen(argv) == 0) //TODO : is piped, no work
	{
		chdir(get_env(env, "HOME"));
		return (STATUS_SUCCESS);
	}
	result = chdir(argv[0]);
	result = result == 0 ? STATUS_SUCCESS : STATUS_FAIL;
	if (fd != NULL && result == STATUS_SUCCESS)
		chdir("..");
	if (result == STATUS_FAIL)
		ft_write_n(1, "cd : No file or directory.");
	return (result);
}

static int	pwd(int *fd)
{
	char	path[100];
	char	*temp;
	int		descriptor;

	descriptor = fd == NULL ? 1 : fd[1];
	temp = getcwd(path, 100);
	ft_write_n(descriptor, temp);
	return (STATUS_SUCCESS);
}

int		echo(char **argv, int *fd, char ***env)
{
	int		descriptor;
	int		n_flag;
	int		i;

	descriptor = fd == NULL ? 1 : fd[1];
	n_flag = FALSE;
	i = -1;
	if (!ft_strcmp(argv[0], "-n"))
	{
		n_flag = TRUE;
		i++;
	}
	while (argv[++i + 1])
	{
		ft_write(descriptor, argv[i]);
		ft_write(descriptor, " ");
	}
	if (!n_flag)
		ft_write_n(descriptor ,argv[i]);
	else
		ft_write(descriptor, argv[i]);
}

int		test(int *fd)
{
	if (fd == NULL)
	{
		ft_write_n(1, "no test");
		return (STATUS_SUCCESS);
	}
	char buf[100];
	read(fd[0], buf, 100);
	printf("%d\n", ft_strlen(buf));
	ft_write(fd[1], "work ?");
	ft_write_n(fd[1], buf);
	return (STATUS_SUCCESS);
}

int		internal_program(char **argv, int *fd, char ****env)
{
	int	program;

	program = check(argv[0]);
	if (program == CD)
		return (cd(++argv, fd, *env));
	else if (program == PWD)
		return (pwd(fd));
	else if (program == EXPORT)
		return (export(++argv, fd, env));
	else if (program == ENV)
		return (env_(++argv, fd, *env));
	else if (program == UNSET)
		return (unset(++argv, fd, env));
	else if (program == EXIT)
		return (STATUS_EXIT);
	else if (program == ECHO)
		return (echo(++argv, fd, *env));
	else if (program == 500)
		return (test(fd));
}
