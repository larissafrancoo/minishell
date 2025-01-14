#include "../include/minishell.h"

int char_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int char_redirect(char c)
{
    return (c == '<' || c == '>');
}

int str_space(char *str)
{
    if (!str || !*str)
        return (0);
    while (*str)
    {
        if (!char_space(*str))
            return (0);
        str++;
    }
    return (1);
}

void change_flag(int c, int *single_flag, int *double_flag)
{
    if (c == 39 && *double_flag == 0)
        *single_flag = !*single_flag;
    else if (c == 34 && *single_flag == 0)
        *double_flag = !*double_flag;
}

int print_error(t_token_type type)
{
    if (type == PIPE)
        ft_putstr_fd("minishell: syntax error near unexpected token '|'\n", STDERR_FILENO);
    else if (type == REDIR_IN)
        ft_putstr_fd("minishell: syntax error near unexpected token '<'\n", STDERR_FILENO);
	else if (type == REDIR_OUT)
		ft_putstr_fd("minishell: syntax error near unexpected token '>'\n", STDERR_FILENO);
	else if (type == REDIR_APPEND)
		ft_putstr_fd("minishell: syntax error near unexpected token '>>'\n", STDERR_FILENO);
	else if (type == HEREDOC)
		ft_putstr_fd("minishell: syntax error near unexpected token '<<'\n", STDERR_FILENO);
	else
		ft_putstr_fd("minishell: syntax error near input\n", STDERR_FILENO);
    return (1);
}


