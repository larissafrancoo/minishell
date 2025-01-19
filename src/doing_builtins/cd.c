#include "minishell.h"


static void	ft_update_env(char *path, t_env *env)
{
	char	**env_update;

	env_update = malloc (sizeof(void *) * 3);
	env_update[0] = ft_strdup("export ");
	env_update[2] = NULL;
	if (ft_arr_srch(env->var_list, "OLDPWD") != -1)
	{
		env_update[1] = ft_strjoin("OLDPWD=", env->pwd);
		ft_export(env_update, env);
	}
	free(env->pwd);
	if (!path)
		env->pwd = "memes";
	else
		env->pwd = ft_strdup(path);
	if (ft_arr_srch(env->var_list, "PWD") != -1)
	{
		env_update[1] = ft_strjoin("PWD=", env->pwd);
		ft_export(env_update, env);
	}
	ft_arr_free(env_update);
}

static void	ft_follow_path(char *path, t_env *env)
{
	if (!path || !ft_strncmp(path, "~", 2))
	{
		if (chdir(ft_find_env(env->var_list, "HOME") + 5))
		{
			ft_printf("cd: HOME not set\n");
			status_g = 1;
			return ;
		}
	}
	else if (!ft_strncmp(path, "-", 2))
	{
		if (chdir(ft_find_env(env->var_list, "OLDPWD") + 7))
		{
			ft_printf("cd: OLDPWD not set\n");
			status_g = 1;
			return ;
		}
	}
	else if (chdir(path))
	{
		ft_printf("cd: %s: No such file or directory\n", path);
		status_g = 1;
		return ;
	}
}

void	ft_cd(char **args, t_env *env)
{
	char	*path;

	status_g = 0;
	if (ft_size(args) > 2)
	{
		ft_printf("cd: too many arguments\n");
		status_g = 1;
		return ;
	}
	ft_follow_path(args[1], env);
	if (!status_g)
	{
		path = getcwd(NULL, 0);
		if (!path)
		{
			ft_printf("cd: failed to retrieve the current directory:
                directory does not exist or is inaccessible.");
		}
		ft_update_env(path, env);
	}
}