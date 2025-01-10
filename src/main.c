#include "../include/minishell.h"

t_shel ft_begin_shell(char **argv, char **env)
{
    t_shell init_shell;

    ft_memset(&init_shell, 0, sizeof(t_shell));
    init_shell.argv = argv;
    init_env(&init_shell.env, env);
    init_shell.fd[IN] = dup(STDIN_FILENO);
    init_shell.fd[OUT] = dup(STDOUT_FILENO);
    return (init_shell);
}

int main(int ac, char **av, char **ev)
{
    t_shel  shell;
    
    
    /*start_function(ev);*/
    
    shell = ft_begin_shell(av, ev)
    while (1)
    {
        ft_prompt
        ft_executer(&shell);
        ft_cdm_clean
    }
    return (0);
}