#include "../include/minishell.h"

int main(int ac, char **av, char **ev)
{
    t_env *env;
    t_token *tokens;
    env = NULL;
    tokens = NULL;
    env = my_env_lst(ev, env);
    readline_function(env, tokens);
    free_env(env);
    return (0);
}