#include "../include/minishell.h"

void start_function(t_intro *shell, char **ev)
{
    ft_memset(shell, 0, sizeof(t_intro));
    shell->env_list = (t_env){NULL, NULL}; //B!EOL
    get_env(&shell->env_list, ev);
    shell->pipe_fd[0] = dup(STDIN_FILENO);
    shell->pipe_fd[1] = dup(STDOUT_FILENO);
    //setup_signal_handling();
}

void parse_input(t_intro *shell)
{
    int p_count;

    if (shell->input && !str_space(shell->input))
    {
        p_count = count_pipe(shell->input);
        shell->cmds = ft_calloc((p_count + 2), sizeof(t_one_cmd *));
        if (shell->cmds)
        {
            split_pipe(shell->input, shell->cmds);
            tokenizator(shell->cmds, p_count);
        }
    }
}
// void parse_input(t_intro *shell)
// {
//     int p_count;

//     if (!shell->input || str_space(shell->input))
//         return ;
//     p_count = count_pipe(shell->input);
//     shell->cmds = ft_calloc((p_count + 2), sizeof(t_one_cmd *));
//     if (!shell->cmds)
//         return ;
//     split_pipe(shell->input, shell->cmds);
//     tokenizator(shell->cmds, p_count);
// }
/*---------------------------------------------------------------------*/
//Essas ainda estou decidindo

void add_token(t_var_etc *etc, int start, int end, t_token_type type)
{
    t_token *new_token;
    int length;

    length = end - start;
    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return ;
    new_token->piece = malloc(length + 1);
    if (!new_token->piece)
    {
        free(new_token);
        return ;
    }
    ft_strncpy(new_token->piece, etc->cmd + start, length);
    new_token->piece[length] = '\0';
    new_token->type = type;
    new_token->next = NULL;
    new_token->prev = *etc->last_token;
    if (*etc->last_token)
        (*etc->tokens_list)->next = new_token;
    else
        *etc->tokens_list = new_token;
    *etc->last_token = new_token;
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	while (s1[i] && i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}
/*--------------------------------------------------------*/

/*--------------------------------------------------------*/
// void init_split_ctx(t_spliter *ctx)
// {
// 	ctx->start = 0;
// 	ctx->index = 0;
// 	ctx->quote_single = 0;
// 	ctx->quote_double = 0;
// }
/*----------------------------------------------------------------------*/