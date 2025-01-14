#include "../include/minishell.h"

static int vetor_size(char **ev)
{
    int i;

    i = 0;
    while (ev[i])
        i++;
    return (i);
}

static t_env_node *new_env_node(char *key, char *value)
{
    t_env_node *node;

    node = (t_env_node *) malloc(sizeof(t_env_node));
    if (!node)
        return (NULL);
    node->key = ft_strdup(key);
    if (!node->key)
    {
        free(node);
        return (NULL);
    }
    node->value = ft_strdup(value);
    if (!node->value)
    {
        free(node->value);
        free(node);
        return (NULL);
    }
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

static void env_addback(t_env *list, t_env_node *new_node)
{
    if (!new_node && !list)
        return ;
    if (!list->head)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
}

static char *get_env_content(char *ev, int sig)
{
    char *content;
    char *equal;

    equal = ft_strchr(ev, '=');
    if (!equal)
        return (NULL);
    if (sig == 0)
        content = ft_strndup(ev, ft_strchr(ev, '=') - ev);
    else if (sig == 1)
        content = ft_strdup(ft_strchr(ev, '=') + 1);
    return (content);
}

void get_env(t_env *list, char ** ev)
{
    int i;
    int size = vetor_size(ev);
    t_env_node *new;
    char *key;
    char *value;

    i = -1;
    while (++i < size)
    {
        key = get_env_content(ev[i], 0);
        value = get_env_content(ev[i], 1);
        if (!key)
            free(key);
        if (!value)
            free(value);
        new = new_env_node(key, value);
        if (!new)
            free_env_error(&list, &key, &value);
        if (!key || !value || !new)
            return ;
        env_addback(list, new);
        free (key);
        free (value);
    }
}