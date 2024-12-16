#include "../include/minishell.h"

int main(int ac, char **av, char **ev)
{
    t_env *env;
    env = NULL;
    env = my_env_lst(ev, env);
    start_function(env);
    free_env(env);
    return (0);
}