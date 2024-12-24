#include "../include/minishell.h"
int find_next_char_for_expand(char *str, int idx)
{
    int flag;

    flag = 0;
    if (!str)
        return (-1);
    while (str[idx])
    {
        if (ft_isalpha(str[idx]) || str[idx] == '_')
        {
            if (!str[idx + 1])
                return (idx);
            else
                idx++;
        }
        else
            break ;
    }
    if (idx == 0)
        return (idx);
    else
        return (idx - 1);
}

char	*get_word_for_expand(char *str, int idx)
{
    int     wlen;
    int     end_word;
    int     iret;
    char    *ret;

    iret = -1;
    end_word = find_next_char_for_expand(str, idx);
    if (end_word == -1)
        return (NULL);
    wlen = (end_word - idx) + 1;
    ret = (char *) malloc((wlen + 1) * sizeof(char));
    if (!ret)
        return (NULL);
    while (++iret < wlen)
        ret[iret] = str[idx++];
    printf("idx iret: %d - idx str: %d\n", iret, idx);
    ret[iret] = '\0';
    printf("achei uma palavra: %s\n", ret);
    return (ret);
}
/*
char *expand_strjoin(char *s1, char *s2)
{
    int i;
    int x;
    char *ret;

    i = -1;
    x = 0;
    if (!s1 || !s2)
        return (NULL);
    ret = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!ret)
        return(NULL);
    while (s1[i++])
        ret[i] = s1[i];
    if (s1[0])
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

char	*substr_for_expand(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	o;
	char			*ret;

	i = start;
	o = 0;
	if (!s || len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (o < len)
	{
		ret[o] = s[i];
		i++;
		o++;
	}
	ret[o] = '\0';
	return (ret);
}
*/