#include "../include/minishell.h"

int count_pipe(char *str)
{
    int i;
    int count;
    int single_flag;
    int double_flag;

    i = -1;
    count = 0;
    single_flag = 0;
    double_flag = 0;
    while (str[++i])
    {
        change_flag(str[i], &single_flag, &double_flag);
        if ((str[i] == 124) && !single_flag && !double_flag)
            count++;
    }
    return (count);
}

static int out_of_quotes(int c, int *single_flag, int *double_flag)
{
        change_flag(c, single_flag, double_flag);
        return (c == 124 && !(*single_flag) && !(*double_flag));
}

static void get_pipe_piece(char *str, t_one_cmd **cmds, int *start, int *index, int current)
{
    t_one_cmd *new;

    new = create_cmd(str, *start, current - *start);
    if (new)
        cmds[*index++] = new;
    *start = current + 1;
}

void split_pipe(char *str, t_one_cmd **cmds)
{
    int start;
    int index;
    int single_flag;
    int double_flag;
    int i;

    start = 0;
    index = 0;
    single_flag = 0;
    double_flag = 0;
    i = -1;
    while (str[++i])
    {
        if (out_of_quotes(str[i], &single_flag, &double_flag))
            
            get_pipe_piece(str, cmds, &start, &index, i);
        cmds[index] = NULL;
    }
}