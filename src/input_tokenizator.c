#include "../include/minishell.h"

t_token	*token_lstlast(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	token_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*aux;

	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			aux = token_lstlast(*lst);
			aux->next = new;
		}
	}
}

void	free_tokens(t_token *list)
{
	t_token	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->str);
		free(temp);
	}
}

int check_type_input(char *str, int prev)
{
    if (strcmp(str, "|"))
        return (PIPE);
    else if (strcmp(str, ">"))
        return (REDIR);
    else if (strcmp(str, ">>"))
        return (REDIR);
    else if (strcmp(str, "<"))
        return (REDIR);
    else if (strcmp(str, "<<"))
        return (REDIR);
    else
    {
        printf("EU CHEGUE AQUI\n");
        if (prev == PIPE)
            return (CMD);
        else if (prev == REDIR)
            return (REDIR_ARG);
        else if (prev == CMD)
            return (ARG);
        else
        {
            printf("ERRO PARA COLOCAR O TYPE\n");
            return (0);
        }
    }
}

void add_type_in_the_list(t_token **lst)
{
    t_token *aux;
    int prev_token;
    int this_type;

    aux = *lst;
    prev_token = PIPE;
	while (aux->next)
    {
        this_type = check_type_input(aux->str, prev_token);
        aux->type = this_type;
        prev_token = this_type;
        aux = aux->next;
    }
    aux->type = check_type_input(aux->str, prev_token);
}

t_token	*token_lstnew(char *first_str)
{
	t_token	*list;

	list = (t_token *) malloc(sizeof(t_token));
	if (!list)
		return (NULL);
	list->str = first_str;
	list->next = NULL;
	return (list);
}

t_token *tokenizator(char *rd_input, t_token *token_list)
{
    int     i;
    char    **splited_input;
    t_token *token;
    t_token_type type;

    i = -1;
    splited_input = mod_split_input(rd_input);
    if (!splited_input)
        return (NULL);
    while (splited_input[++i])
    {
        token = token_lstnew(ft_strdup(splited_input[i]));
        if (!token)
        {
            free_tokens(token_list);
            return (NULL);
        }
    	token_lstadd_back(&token_list, token);
    }
    add_type_in_the_list(&token_list);
    split_free(splited_input, i);
    return (token_list);
}

int do_tokens(char *rd_input)
{
    int     i;
    t_token *tmp;
    t_token *tokens;

    i = -1;
    tokens = NULL;
    if (input_check(rd_input) != 0)
        return (input_check(rd_input));
    tokens = tokenizator(rd_input, tokens);
    if (!tokens)
        return (ERROR_WORD);
    printf("Sucesso!\n");
    tmp = tokens;
    while (tmp)
    {
        printf("Str da struct: %s\n", tmp->str);
        printf("Tipo do str: %d\n\n", tmp->type);
        tmp = tmp->next;
    }
    free_tokens(tokens);
    return (0);
}
/*
int main(void)
{
	int i = -1;
    t_env *tmp;
	t_env *env_list;
    env_list = NULL;

    env_list = my_env_lst(ev, env_list);

    tmp = env_list;
    while (ev[++i])
        printf("String do env: %s\n\n", ev[i]);
    printf("----------------------------------------\n");
    while (tmp)
    {
        printf("Str da struct: %s\n", tmp->key);
        printf("Frase da struct: %s\n\n", tmp->str);
        tmp = tmp->next;
    }

    free_env(env_list);
	return (0);
}
*/
/*
t_env	*my_env_lst(char **ev, t_env *env_list)
{
	int		i;
	int		equal_index;
	char	*key;
	char	*str;
	t_env	*new;

	i = -1;
	while (ev[++i])
	{
		equal_index = first_equal(ev[i]);
		key = ft_substr(ev[i], 0, equal_index);
		if (!key)
			return (NULL);
		str = ft_substr(ev[i], equal_index + 1, strlen(ev[i]) - equal_index - 1);
		if (!str)
		{
			free (key);
			return (NULL);
		}
		new = my_lstnew(key, str);
		//fazer tratamento caso dê errado
		my_lstadd_back(&env_list, new);
	}
	return (env_list);
}
*/