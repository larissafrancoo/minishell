#include "minishell.h"

#include "../include/minishell.h"

int	ft_env(t_env *env_list)
{
	t_env	*current;

	if (!env_list)
	{
		status_g = 1; // Indica erro
		//ft_putstr_fd("minishell: env: lista de ambiente não encontrada\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}

	current = env_list;
	while (current)
	{
		if (current->key && current->value)
		{
			ft_putstr_fd(current->key, STDOUT_FILENO);
            ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(current->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		current = current->next;
	}
	status_g = 0;
	return (EXIT_SUCCESS);
}
