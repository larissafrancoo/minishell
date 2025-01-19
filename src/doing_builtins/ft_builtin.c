#include "minishell.h"

void	ft_exec_builtins(char **args, t_env *env, t_shell *shell)
{
	if (ft_strncmp(args[0], "echo", 5) == 0)
		ft_echo(args);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		ft_cd(args, env);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		ft_pwd(args, env);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		ft_export(args, env);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		ft_unset(args, env);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		ft_env(args, env);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		ft_exit(args, env, sh);
}

void	ft_builtin_exec(t_shell *shell, t_cmd *cmd)
{
	if (!confirm(cmd))
		return ;
	ft_setfd(STDIN_FILENO, &cmd->fdin, STDIN_FILENO);
	ft_setfd(STDOUT_FILENO, &cmd->fdout, STDOUT_FILENO);
	ft_execute_builtins(cmd->args, sh->env, sh);
	dup2(sh->io[IN], STDIN_FILENO);
	dup2(sh->io[OUT], STDOUT_FILENO);
}

int ft_isbuiltin(char *cmd)
{
	int         i;
    int         j;
	const char	**built;

	built = malloc(sizeof(char *) * 8);
	if (!built)
		return (0);
	built[0] = ft_strdup("echo");
	built[1] = ft_strdup("cd");
	built[2] = ft_strdup("pwd");
	built[3] = ft_strdup("export");
	built[4] = ft_strdup("unset");
	built[5] = ft_strdup("env");
	built[6] = ft_strdup("exit");
	built[7] = NULL;
	i = 0;
	while (built[i])
	{
		if (!ft_strncmp(built[i], cmd, ft_strlen(built[i])))
		{
			j = 0;
            while (j < 7 && built[j])
				free((void *)built[j]);
			free(built);
			return (1);
		}
		i++;
	}
	j = 0;
    while (j < 7 && built[j])
	    free((void *)built[j]);
	free(built);
	return (0);
}
