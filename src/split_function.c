#include "../include/minishell.h"

char	*word_between_spaces(char *str, int idx)
{
    int     wlen;
    int     end_word;
    int     iret;
    char    *ret;

    iret = -1;
    end_word = find_next_char(str, idx);
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
    return (ret);
}

void	split_free(char **str, size_t o)
{
	size_t	i;

	i = 0;
	while (i < o)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char    **mod_split_input(char *str)
{
    int     istr;
    int     iret;
    char    **ret;

    istr = 0;
    iret = 0;
    if (!str)
        return (NULL);
    ret = (char **) ft_calloc(word_count(str) + 1, sizeof(char *));
    if (!ret)
        return (NULL);
    while (ret && str[istr])
    {
        if (!is_space(str[istr]))
        {
            ret[iret] = word_between_spaces(str, istr);
            if (!ret[iret])
            {
                split_free(ret, iret);
                return (NULL);
            }
            istr = find_next_char(str, istr);
            iret++;
        }
        istr++;
    }
    ret[iret] = NULL;
    return (ret);
}