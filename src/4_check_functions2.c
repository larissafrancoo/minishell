#include "../include/minishell.h"

static int has_a_pair(const char *str)
{
    if (!str || !str[0])
        return (0);
    if ((*str == 39 || *str == 34) && ft_strchr(str + 1, *str))
        return (1);
    return (0);
}

static int isop(const char *str)
{
    static const char *op[] = {"<<", ">>", "<", ">", "|", NULL};
    int i;
    int size;

    i = 0;
    if (!str || !*str)
        return (0);
    while (op[i])
    {
        size = strlen(op[i]);
        if (ft_strncmp(op[i], str, size) == 0)
            return (size);
        i++;
    }
    return (0);
}

static int handle_quotes(char *str, int *i, int *flag)
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

static int check_operators(char *str)
{
    int op_size;
    int next_op_size;
    const char *next_c;

    op_size = isop(str);
    if (!op_size)
        return (0);
    next_c = str + op_size;
    while (*next_c && char_space(*next_c))
        next_c++;
    next_op_size = isop(next_c);
    if (next_op_size)
        if (char_redirect(*str) && char_redirect(*next_c))
            return (print_error(REDIR_IN));
    if (!*next_c)
    {
        if (*str == '|')
            return (print_error(PIPE));
        ft_putstr_fd("minishell: syntax error near unexpected token 'newline'\n", STDERR_FILENO);
        return (1);
    }
    return (0);
}

int valid_input(char *str)
{
    int i;
    int flag;

    i = -1;
    flag = 0;
    while (str[++i])
    {
        if (!handle_quotes(str, &i, &flag))
            return (0);
        if (!flag && check_operators(&str[i]))
            return (0);
    }
    return (1);
}