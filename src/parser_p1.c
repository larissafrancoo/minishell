#include "../include/minishell.h"

int parser_home(char *input, t_token *token_lst, t_env *env_lst)
{
    int inret;

    inret = 0;
    inret = do_tokens(input, token_lst, env_lst);
    inret = check_builtins(token_lst, env_lst);
    return (inret);
}