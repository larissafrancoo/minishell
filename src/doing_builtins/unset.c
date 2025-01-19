#include "minishell.h"

int search_equal(char **array_str, char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    if (array_str && str)
    {
        while (array_str[i])
        {
            if (!ft_strncmp(array_str[i], str, len))
            {
                if (array_str[i][len] == '=')
                    return (i);
            }
            i++;
        }
    }
    return (-1);
}

static int validate_identifier(char *identifier)
{
    int i;

    if (!identifier || !(ft_isalpha(identifier[0]) || identifier[0] == '_'))
    {   ft_printf("unset: `%s': not a valid identifier\n", identifier);
        status_g = 1;
        return (1);
    }
    i = 0;
    while (identifier[i])
    {
        if (!(ft_isalnum(identifier[i]) || identifier[i] == '_'))
        {
            ft_printf("unset: `%s': not a valid identifier\n", identifier);
            status_g = 1; 
            return (1);
        }
        i++;
    }
    return (0);
}

static void remove_environment_variable(t_env *env, int position)
{
    if (!env->var_list[position])
        return;
    free(env->var_list[position]);
    while (env->var_list[position + 1])
    {
        env->var_list[position] = env->var_list[position + 1];
        position++;
    }
    env->var_list[position] = NULL;
}

void ft_unset(char **args, t_env *env)
{
    int i;
    int position;
    
    status_g = 0;
    i = 0;
    while (args[i])
    {
        if (validate_identifier(args[i]))
            break;
        position = search_equal(env->var_list, args[i]);
        if (position != -1)
            remove_environment_variable(env, position);
        i++;
    }
}
