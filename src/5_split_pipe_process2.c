#include "../include/minishell.h"

static void init_one_cmd(t_one_cmd *node)
{
    node->cmd = NULL;
    node-> fd_in = -1;
    node->fd_out = -1;
    node->pid = -1;
    node->token_list = NULL;
}

static int	calculate_trim_bounds(char *str, int start, int len,
int *trim_end)
{
	int	trim_start;

	*trim_end = start + len - 1;
	trim_start = start;
	while (trim_start <= *trim_end && char_space(str[trim_start]))
		trim_start++;
	while (*trim_end > trim_start && char_space(str[*trim_end]))
		(*trim_end)--;
	return (trim_start);
}

t_one_cmd *create_cmd(char *str, int start, int len)
{
    t_one_cmd *node;
    int trim_start;
    int trim_end;

    node = malloc(sizeof (t_one_cmd));
    if (!node)
        return (NULL);
    init_one_cmd(node);
    trim_start = calculate_trim_bounds(str, start, len, &trim_end);
    len = trim_end - trim_start + 1;
    if (len <= 0)
    {
        free(node);
        return (NULL);
    }
    node->cmd = malloc(len + 1);
    if (!node->cmd)
    {
        free(node);
        return (NULL);
    }
    ft_strncpy(node->cmd, &str[trim_start], len);
    node->cmd[len] = '\0';
    return (node);
}