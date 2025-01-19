#include "minishell.h"

int status_g = 0;
// Função para liberar arrays de strings
void free_split(char **split)
{
    int i = 0;
    if (!split)
        return;
    while (split[i])
        free(split[i++]);
    free(split);
}

// Verifica se o argumento é válido
static int ft_check_arg(const char *arg)
{
    int i = 0;

    if (ft_isalpha(arg[i]) || arg[i] == '_')
    {
        while (ft_isalnum(arg[++i]) || arg[i] == '_')
            ;
        if (arg[i] == '=')
            return 0; 
        if (arg[i] == '\0')
            return 1; 
    }
    fprintf(stderr, "export: `%s': not a valid identifier\n", arg);
    status_g = 1;
    return 1; 
}

// Lista todas as variáveis de ambiente
static void ft_list_env(t_env_node *env_list)
{
    t_env_node *current = env_list;
    while (current)
    {
        printf("declare -x %s=\"%s\"\n", current->key, current->value);
        current = current->next;
    }
}

// Atualiza variável de ambiente, se já existir
static int update_env_var(t_env_node **env_list, char **split)
{
    t_env_node *current = *env_list;

    while (current)
    {
        if (ft_strcmp(current->key, split[0]) == 0)
        {
            free(current->value);
            current->value = strdup(split[1]);
            free_split(split);
            return EXIT_SUCCESS;
        }
        current = current->next;
    }

    return EXIT_FAILURE; // Caso não encontre a variável
}

// Atualiza ou adiciona variável ao ambiente
static int update_or_add_var(t_env_node **env_list, char *arg)
{
    char **split = ft_split(arg, '=');
    t_env_node *current;
    t_env_node *new_node;

    if (!split || !split[0] || !split[1])
    {
        free_split(split);
        return EXIT_FAILURE;
    }
    if (update_env_var(env_list, split) == EXIT_SUCCESS)
        return EXIT_SUCCESS;
    new_node = malloc(sizeof(t_env_node));
    if (!new_node)
    {
        free_split(split);
        return EXIT_FAILURE;
    }
    new_node->key = strdup(split[0]);
    new_node->value = strdup(split[1]);
    new_node->next = *env_list;
    *env_list = new_node;
    free_split(split);
    return EXIT_SUCCESS;
}

// Função principal para exportar variáveis
int ft_export(t_token *token, t_env_node **env_list)
{
    if (!token || !env_list)
        return EXIT_FAILURE;
    if (!token->piece)
    {
        ft_list_env(*env_list);
        return EXIT_SUCCESS;
    }
    if (!ft_check_arg(token->piece))
        return update_or_add_var(env_list, token->piece);
    return EXIT_FAILURE;
}
