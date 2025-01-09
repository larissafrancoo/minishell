#include "../include/minishell.h"

void start_function(t_intro *shell, char **ev)
{
    ft_memset(shell, 0, sizeof(t_intro));
    shell->env_list = (t_env){NULL, NULL}; //BRABO!! Entender o lance
    get_env(&shell->env_list, ev);
    shell->pipe_fd[0] = dup(STDIN_FILENO);
    shell->pipe_fd[1] = dup(STDOUT_FILENO);
    //setup_signal_handling();
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

int char_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int check_input(char *input)
{
    if (error_input(input))
        return (1);
    else if (input[0] == '\0')
        return (1);
    else if (str_space(input))
        return (1);
    return (0);
}

int error_input(char *input)
{
    if (check_quotes(input))
    {
        return (1);
    }
    if (check_pipes(input))
    {
        return (1);
    }
    if (!valid_input(input))
    {
        return (1);
    }
    return (0);
}

int check_quotes(char *str)
{
    int i;
    int flag;

    i = -1;
    flag = 0;
    while (str[++i])
    {
		if ((str[i] == 34 || str[i] == 39) && flag == 0)
			flag = str[i];
		else if (str[i] == flag)
			flag = 0;
    }
	if (flag == 0)
		return (0);
    else if (flag == 39)
        ft_putstr_fd("minishell: syntax error: unexpected EOF while \
looking for matching '\n", STDERR_FILENO);
    else if (flag == 34)
        ft_putstr_fd("minishell: syntax error: unexpected EOF while \
looking for matching \"\n", STDERR_FILENO);
	return (1);
}

int check_pipes(char *str)
{
    int i;
    int single_flag;
    int double_flag;

    i = -1;
    while (str[++i] && char_space(str[i]))
        continue ;
    if (str[i] == 124)
        return (print_error(PIPE));
    while (str[i])
    {
        change_flag(str[i], &single_flag, &double_flag);
        if (str[i] == 124 && !single_flag && !double_flag)
            if (invalid_pipe(str, &i))
                return (1);
        i++;
    }
    return (0);
}

int print_error(t_token_type type)
{
    if (type == PIPE)
        ft_putstr_fd("minishell: syntax error near unexpected token '|'\n", STDERR_FILENO);
    return (1);
}

void change_flag(int c, int *single_flag, int *double_flag)
{
    if (c == 39 && *double_flag == 0)
        *single_flag = !*single_flag;
    else if (c == 34 && *single_flag == 0)
        *double_flag = !*double_flag;
}

static int invalid_pipe(char *str, int *i)
{
    int p;

    p = *i + 1;
    while (str[p] && char_space(str[p]))
        p++;
    if (str[p] == 124 || !str[p])
        return (print_error(PIPE));
    return (0);
}

static int valid_input(char *str)
{
    int i;
    int flag;
    char closing;

    i = -1;
    flag = 0;
    closing = '\0';
    while (str[++i])
    {
        if (!handle_quotes(str, &i, &flag, &closing))
    }
}

int handle_quotes  (char *str, int *i, int *flag)
{
    if (!*flag && (str[*i] == 39 || str[*i] == 34)
        && !has_a_pair(&str[*i]))
        return (0);
    else if (!*flag && has_a_pair(&str[*i]))
        *flag = str[*i];
    else if (*flag == str[*i])
        *flag = 0;
    return (1);
}

int has_a_pair(const char *str)
{
    if (!str || !str[0])
        return (0);
    if ((*str == 39 || *str == 34) && ft_strchr(str + 1, *str))
        return (1);
    return (0);
}