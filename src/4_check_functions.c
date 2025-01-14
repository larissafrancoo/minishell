#include "../include/minishell.h"

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

static int check_pipes(char *str)
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

static int check_quotes(char *str)
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

static int error_input(char *input)
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