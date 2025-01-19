#include "minishell.h"

void	ft_setfd(int fd, t_fd *files, int s)
{
	if (files->fd != -2)
	{
		dup2(files->fd, s);
		ft_fdclean(file);
	}
	else if (fd != s)
		dup2(fd, s);
}

int	confirm(t_cmd *cmd)
{
	if (cmd->fdout.fd == -1)
	{
		access(cmd->fdout.fn, F_OK | W_OK);
		status_g = ft_perror(1, cmd->fdout.fn, 0);
		return (0);
	}
	else if (cmd->fdin.fd == -1)
	{
		access(cmd->fdin.fn, F_OK | R_OK);
		status_g = ft_perror(1, cmd->fdin.fn, 0);
		return (0);
	}
	return (1);
}

void	ft_shclean(t_shell *shell)
{
	close(shell->io[IN]);
	close(shell->io[OUT]);
	ft_cmdclean(&shell->cmd);
}

void	ft_arr_free(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
	}
	free(arr);
}

int	ft_arr_srch(char **arr, char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (arr && str)
	{
		while (arr[++i])
		{
			if (!ft_strncmp(arr[i], str, len))
			{
				if (arr[i][len] == '=')
					return (i);
			}
		}
	}
	return (-1);
}