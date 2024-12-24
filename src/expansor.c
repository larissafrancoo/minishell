#include "../include/minishell.h"

char *expand_strjoin(char *s1, char *s2)
{
    int i;
    int x;
    char *ret;

    i = -1;
    x = -1;
    if (!s1 && !s2)
        return (NULL);
    ret = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!ret)
        return(NULL);
    while (s1[++i])
        ret[i] = s1[i];
    free(s1);
    while (s2[++x])
        ret[i++] = s2[x];
    ret[i] = '\0';
    return (ret);
}

char *find_the_key(char *str, t_env *env_lst)
{
    if (!env_lst)
        return (0);
    while (env_lst->next)
    {
        if (strcmp(env_lst->key, str) == 0)
        {
            free(str);
            str = ft_strdup(env_lst->str);
            return (str);
        }
        else
            env_lst = env_lst->next;
    }
    free (str);
    return (NULL);
}

char *expander(char *str, t_env *env_list)
{
    int i;
    int flag;
    t_env *node;
    char *aux;
    char *ret;

    i = -1;
    flag = 0;
    aux = NULL;
    ret = NULL;
    while (str[++i])
    {
        if (str[i] == '$' && flag == 0)
        {
            ret = ft_substr(str, 0, i);
            i++;
            flag = 1;
        }
        if (flag == 1)
        {
            aux = get_word_for_expand(str, i);
            if (!aux)
            {
                printf("IIIH LASCOU!\n");
                free (ret);
                return (NULL);
            }
            aux = find_the_key(aux, env_list);
            if (aux)
            {
                ret = expand_strjoin(ret, aux);
                free(aux);
            }
            i = find_next_char_for_expand(str, i) + 1; /*Essa variavel tenta acessar o idx depois do '\0'. resolver isso*/
            printf("localização idx: %d| char referente: %c\n", i, str[i]);
            flag = 2;
        }
        if (flag == 2)
        {
            ret = expand_strjoin(ret, &str[i]);
            free(str);
            str = ft_strdup(ret);
            free (ret);
            flag = 0;
        }
    }
    return (str);
}

int main(int ac, char **av, char **ev)
{
    t_env *env_lst;
    env_lst = NULL;
    env_lst = my_env_lst(ev, env_lst);
    char *ret = ft_strdup("lari $HOME a $USER funcao");
    ret = expander(ret, env_lst);  // env_lst já foi criado anteriormente
    printf("{Teste 1}: %s\n", ret);
    free(ret);

    // Teste 2: Expansão com variável em meio à frase
    ret = ft_strdup("Diretório: $HOME, Usuário: $USER");
    ret = expander(ret, env_lst);
    printf("{Teste 2}: %s\n", ret);
    free(ret);

    // Teste 3: Expansão de múltiplas variáveis com texto
    ret = ft_strdup("O caminho é $HOME/$USER/Documents");
    ret = expander(ret, env_lst);
    printf("{Teste 3}: %s\n", ret);
    free(ret);

    // Teste 4: Variável não encontrada
    ret = ft_strdup("Caminho do diretório: $NOT_FOUND");
    ret = expander(ret, env_lst);
    printf("{Teste 4}: %s\n", ret);  // Esperado: "Caminho do diretório: $NOT_FOUND"
    free(ret);

    // Teste 5: Frase sem variáveis
    ret = ft_strdup("Esta frase não contém variáveis");
    ret = expander(ret, env_lst);
    printf("{Teste 5}: %s\n", ret);  // Esperado: "Esta frase não contém variáveis"
    free(ret);

    // Teste 6: Expansão com múltiplos espaços e variáveis
    ret = ft_strdup("$HOME/$USER/Desktop $USER$HOME");
    ret = expander(ret, env_lst);
    printf("{Teste 6}: %s\n", ret);
    free(ret);
    free_env(env_lst);

    return (0);
}