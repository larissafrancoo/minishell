void process_command_pipeline(t_shell *shell)
{
    t_cmd   *cmd;
    t_pid   *lst_cmd;
    int n;

    cmd = shell->cmd;
    lst_cmd = NULL;
    n = dup(0);
    while (cmd)
    {
        if(!cmd->next)
            msh_end_exec(n, cmd, shell, &lst_cmd);
        else
            msh_begin_exec(&n, cmd, shell, &lst_cmd);
    }
}

void ft_executor(t_shell *shell)
{
    t_cmd   *cmd;
    t_pid   *lst_cmd;
    int     n;
    int     pipe;

    if (shell->cmd == NULL)
        return ;
    n = isbuiltin(tem que fazer o builtin);
    if (!shell->cmd->next && n)
        builtin_exec(tem que fazer o builtin);
    else
        process_command_pipeline(shell);
}