#include "../include/minishell.h"

static void init_etc(t_var_etc *etc, t_token **tokens_list, t_token **last_token, char *cmd)
{
	etc->tokens_list = tokens_list;
	etc->last_token = last_token;
	etc->cmd = ft_strdup(cmd);
	*tokens_list = NULL;
	*last_token = NULL;
}

static void make_token_cmd(char *cmd, t_token **token_list, t_token **last)
{
    t_var_etc etc;
    int current;
    int start;
    int is_first_tk;

    current = 0;
    is_first_tk = 1;
    init_etc(&etc, token_list, last, cmd);
    while (cmd[current])
    {
        while (char_space(cmd[current]))
            current++;
        if (!cmd[current])
            break ;
        start = current;
        if (cmd[current] == '>' || cmd[current] == '<')
            handle_redirect(&etc, &current);
        else
            handle_token(&etc, &current, &start, &is_first_tk);
    }
    free(etc.cmd);
}

void tokenizator(t_one_cmd **cmds, int p_count)
{
    int i;
    t_token *last;

    i = -1;
    while (++i <= p_count)
    {
        if (cmds[i] && cmds[i]->cmd)
        {
            last = NULL;
            make_token_cmd(cmds[i]->cmd, &cmds[i]->token_list, &last);
        }
    }
}

// void tokenizator(t_one_cmd **cmds, int p_count)
// {
//     int i;
//     t_token *last;

//     i = -1;
//     while (++i <= p_count)
//     {
//         if (cmds[i] != NULL && cmds[i]->cmd != NULL)
//         {
//             last = NULL;
//             make_token_cmd(cmds[i]->cmd, &cmds[i]->token_list, &last);
//         }
//     }
// }