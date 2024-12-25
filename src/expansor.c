#include "../include/minishell.h"

char *expander_the_input(char *input, t_env *env_lst)
{
    int i;
    char *ret1;
    char *ret2;
    char *ret3;
    char *final;

    i = 0;
    while (input[i] && (input[i] != '$'))
        i++;
    ret1 = get_first_part(input, i);
    ret2 = get_the_key(input, i, env_lst);
    i++;
    while (input[i] && (ft_isalpha(input[i]) || input[i] == '_'))
        i++;
    ret3 = get_final_part(input, i);
    printf("Retorno da função 'get_first_part': |%s|\n", ret1);
    printf("Retorno da função 'get_the_key': |%s|\n", ret2);
    printf("Retorno da função 'get_final_part': |%s|\n", ret3);
    final = join_the_parts(ret1, ret2, ret3);
    printf("Junção dos retornos: |%s|\n", final);
    free(input);
    return (final);
}
// int expansor(t_token *token_lst, t_env *env_lst)
// {
//     t_token *tmp;
//     char *aux;

//     tmp = token_lst;
//     while (tmp->next)
//     {
//         aux = ft_strdup(tmp->str);
//         tmp->str = expander_the_input(aux, env_lst);
//         free(aux);
//         if (!tmp->str)
//         {
//             printf("ERRO COM O EXPANSOR\n");
//             return (0);
//         }
//         printf("Str da struct depois: %s\n", tmp->str);
//         printf("Tipo do str depois: %d\n\n", tmp->type);
//         tmp = tmp->next;
//     }
//     return (1);
// }