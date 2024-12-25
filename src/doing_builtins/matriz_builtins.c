#include "../../include/minishell.h"

int check_builtins(t_token *token_lst, t_env *env_lst)
{
    if (strcmp(token_lst->str, "exit") == 0)
    {
        free_tokens(token_lst);
        return (EXIT_SUCCESS);
    }
/*
    else if (strcmp(input, "env") == 0)
    {
        ret_dtok = print_env(env_list);
        if (!ret_dtok)
        {
            free_env(env_list);
            printf("ERRO NA ENV\n");
        }
    }
    else if (strcmp(rd_input,"pwd") == 0)
    {
        ret_dtok = ft_pwd();
        if (!ret_dtok)
        {
            free_env(env_list);
            printf("ERRO NA PWD\n");
        }
    }
*/
}