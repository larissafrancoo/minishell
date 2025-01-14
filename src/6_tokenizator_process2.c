#include "../include/minishell.h"

static void redirect_type(char *str, int start, t_token_type *redir_type, int *redir_len)
{
    *redir_len = 0;
    if (str[start] == '>' && str[start + 1] == '>')
    {
        *redir_type = REDIR_APPEND;
        *redir_len = 2;
    }
    else if (str[start] == '<' && str[start + 1] == '<')
    {
        *redir_type = HEREDOC;
        *redir_len = 2;
    }
    else if (str[start] == '>')
        *redir_type = REDIR_OUT;
    else if (str[start] == '<')
        *redir_type = REDIR_IN;
}

static void redirect_arg(t_var_etc *etc, int *current, t_token_type arg_type)
{
    int start;
    int single_flag;
    int double_flag;

    start = *current;
    single_flag = 0;
    double_flag = 0;
    while (etc->cmd[*current])
    {
        change_flag(etc->cmd[*current], &single_flag, &double_flag);
        if (!single_flag && !double_flag && (char_space(etc->cmd[*current])
                || etc->cmd[*current] == '>' || etc->cmd[*current] == '<'))
                break ;
            (*current++);
    }
    if (*current > start)
        add_token(etc, start, *current, arg_type);  
}

static t_token_type redir_arg_type(t_token_type redir_type)
{
	if (redir_type == REDIR_APPEND)
		return (APPEND_ARG);
	else if (redir_type == HEREDOC)
		return (HEREDOC_ARG);
	else if (redir_type == REDIR_OUT)
		return (OUT_ARG);
	else if (redir_type == REDIR_IN)
		return (IN_ARG);
	else
		return (CMD_ARG);
}

void handle_redirect(t_var_etc *etc, int *current)
{
    int start;
    t_token_type redir_type;
    int redir_len;

    start = *current;
    redirect_type(etc->cmd, start, &redir_type, &redir_len);
    add_token(etc, start, start + redir_len, redir_type);
    *current += redir_len;
    while (char_space(etc->cmd[*current]))
        (*current)++;
    redirect_arg(etc, current, redir_arg_type(redir_type));
}

void handle_token(t_var_etc *etc, int *current, int *start, int *is_first_tk)
{
    int single_flag;
    int double_flag;
    t_token_type type;

    single_flag = 0;
    double_flag = 0;
    while (etc->cmd[*current])
    {
        change_flag(etc->cmd[*current], &single_flag, &double_flag);
		if ((!single_flag && !double_flag)
			&& ((etc->cmd[*current] == '>' || etc->cmd[*current] == '<')
				|| char_space(etc->cmd[*current])))
			break ;
        (*current)++;
    }
    if (*current > *start)
    {
        if (*is_first_tk)
            type = CMD;
        else
            type = CMD_ARG;
        add_token(etc, *start, *current, type);
        *is_first_tk = 0;
    }
}