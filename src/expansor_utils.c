#include "../include/minishell.h"

char *replace_the_part(char *str, t_env *env_lst)
{
    t_env *aux;

    aux = env_lst;
    while (aux->next)
    {
        if (strcmp(aux->key, str) == 0)
            return (ft_strdup(aux->str));
        aux = aux->next;
    }
    return (NULL);
}

char *get_first_part(char *str, int idx)
{
    int i;
    char *ret;

    printf("Index passado para a função 'get_first_part': %d - char %c|\n", idx, str[idx]);
    i = 0;
    ret = (char *) malloc((idx + 1) * sizeof(char));
    if (!ret)
    {
        printf("ERRO NO GET_FIRST_PART");
        return (NULL);
    }
    while (i < idx)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

char *get_the_key(char *str, int idx, t_env *env_lst)
{
    int i;
    int len;
    char *ret;
    char *aux;

    if (!str)
        return (NULL);
    if (str[idx] != '$')
    {
        printf("\nVocê não está me passando uma chave.\n");
        return (NULL);
    }
    idx++;
    i = idx;
    while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
        i++;
    len = i - idx;
    printf("Tamanho de len em 'get_the_key': %d\n", len);
    aux = (char *) malloc((len + 1) * sizeof(char));
    if (!aux)
        return (NULL);
    i = 0;
    while (i < len)
        aux[i++] = str[idx++];
    aux[i] = '\0';
    ret = replace_the_part(aux, env_lst);
    free(aux);
    return (ret);
}

char *get_final_part(char *str, int idx)
{
    int i;
    int len;
    char *ret;

    if (!str[idx])
        return (NULL);
    i = idx;
    while (str[i])
        i++;
    len = i - idx;
    printf("Tamanho de len em 'get_final_part': %d\n", len);
    ret = (char *) malloc((len + 1) * sizeof(char));
    if (!ret)
        return (NULL);
    i = 0;
    while (i < len)
        ret[i++] = str[idx++];
    ret[i] = '\0';
    return (ret);
}

char *join_the_parts(char *p1, char *p2, char *p3)
{
    char *aux;

    if (!p1 && !p2 && !p3)
        return (NULL);
    else if (p1 && p2 && p3)
    {
        aux = ft_strjoin(p1, p2);
        free(p1);
        free(p2);
        p1 = ft_strjoin(aux, p3);
        free(aux);
        free(p3);
        return (p1);
    }
    else if (p1)
    {
        if (!p2 && !p3)
            return (p1);
        else if (!p2)
        {
            aux = ft_strjoin(p1, p3);
            free(p1);
            free(p3);
            return (aux);
        }
        else if (!p3)
        {
            aux = ft_strjoin(p1, p2);
            free(p1);
            free(p2);
            return (aux);
        }
    }
    else if (p2)
    {
        if (!p3)
            return (p2);
        else
        {
            aux = ft_strjoin(p2, p3);
            free(p2);
            free(p3);
            return (aux);
        }
    }
    else
        return (p3);
}