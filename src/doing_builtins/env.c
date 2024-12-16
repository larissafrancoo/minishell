#include "../../include/minishell.h"

int print_env(t_env *env_list)
{
    int i = -1;
    t_env *tmp;

    if(!env_list)
        return (0);
    tmp = env_list;
    while (tmp)
    {
        printf("%s=", tmp->key);
        printf("%s\n", tmp->str);
        tmp = tmp->next;
    }
    return (1);
}