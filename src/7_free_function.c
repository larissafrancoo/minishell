#include "../include/minishell.h"

static void    free_tokens(t_token *token_list)
{
    t_token *node;
    t_token *next;

    node = token_list;
    while (node)
    {
        next = node->next;
        free(node->piece);
        node->piece = NULL;
        node->prev = NULL;
        node->next = NULL;
        free(node);
        node = next;
    }
}

void	free_all_cmds(t_one_cmd ***cmds)
{
    int i;

    if (!cmds || !*cmds)
        return ;
    i = -1;
    while ((*cmds)[++i])
    {
        free_tokens((*cmds)[i]->token_list);
        (*cmds)[i]->token_list = NULL;
        free((*cmds)[i]->cmd);
        (*cmds)[i]->cmd = NULL;
        free((*cmds)[i]);
        (*cmds)[i] = NULL;
    }
    free(*cmds);
    *cmds = NULL;
}

void free_env_error(t_env **list, char **key, char **value)
{
    free(*key);
    *key = NULL;
    free(*value);
    *value = NULL;
    free_env(*list);
    *list = NULL;
}

void free_env(t_env *list)
{
    t_env_node *node;
    t_env_node *next;
    
    if(!list || !list->head)
        return ;
    node = list->head;
    while (node)
    {
        next = node->next;
        free(node->key);
        free(node->value);
        free(node);
        node = next;
    }
    list->head = NULL;
    list->tail = NULL;
}