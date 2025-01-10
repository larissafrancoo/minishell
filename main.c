#include "../include/minishell.h"

int main(int ac, char **av, char **ev)
{
    t_intro shell;

    (void)ac;
    (void)av;

    start_function(&shell, ev);
    while (1)
    {
        shell.input = readline("nickname@123:~/um/caminho/qualquer$ ");
        if (shell.input == NULL)
            break ;
        if (!str_space(shell.input))
            add_history(shell.input);
        if (check_input(shell.input))
        {
            free(shell.input);
            continue ;
        }
        go_minibash(&shell);
    }
    rl_clear_history();
    //cleanup_resourses(NULL, NULL, shell.fd, &shell);
    return (42);
}

void	go_minibash(t_intro *shell)
{
	parse_input(shell);
	if (shell->cmds)
		free_all_cmds(&shell->cmds);
    free(shell->input);
}