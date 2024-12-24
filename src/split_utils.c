#include "../include/minishell.h"

int is_space(int c)
{
    if (c == ' ' || c == '\t')
        return (c);
    return (0);
}

/*
Função: find_next_char

Descrição:
Encontra o próximo caractere de espaço ou o final da string,
a partir do índice fornecido, levando em consideração a
presença de aspas (simples ou duplas).

Parâmetros:
- char *str: A string onde será realizada a busca.
- int idx: O índice inicial para a busca.

Retorno:
- int: O índice do último caractere da palavra/frase encontrado
antes de espaço ou final da string, ou -1 se não encontrar
nenhum caractere relevante.
*/

int is_premium(char *str, int i)
{
    if (str[i] == '|')
        return (i);
    else if (str[i] == '>')
    {
        if (str[i + 1] && (str[i + 1] == '>'))
            return (++i);
        return (i);
    }
    else if (str[i] == '<')
    {
        if (str[i + 1] && (str[i + 1] == '<'))
            return (++i);
        return (i);
    }
    return (-1);
}

int find_next_char(char *str, int idx)
{
    int flag;

    flag = 0;
    while (str[idx])
    {
//        printf("idx: %i    AAAAAAAAAAAAAAAAAH\n", idx);
		if ((str[idx] == 34 || str[idx] == 39) && flag == 0)
			flag = str[idx];
		else if (str[idx] == flag)
			flag = 0;
        else if ((is_premium(str, idx) != -1) && flag == 0)
            return (is_premium(str, idx));
		if (is_space(str[idx]) && flag == 0)
            return (idx - 1);
		if ((!str[idx + 1]) && flag == 0)
			return (idx);
        else if ((is_premium(str, idx + 1) != -1) && flag == 0)
            return (idx);
        idx++;
    }
    return (-1);
}

/*
Função: word_count

Descrição:
Conta o número de palavras em uma string,
ignorando espaços e tratando corretamente as palavras entre aspas.

Parâmetros:
- char *str: A string a ser analisada.

Retorno:
- size_t: O número de palavras encontradas na string.
*/

size_t  word_count(char *str)
{
    size_t  i;
    size_t  count;

    i = -1;
    count = 0;
    if (!str)
        return (0);
    while (str[++i])
    {
        if (!is_space(str[i]))
        {
            i = find_next_char(str, i);
            count++;
        }
    }
    return (count);
}

/*
Função: all_quotes_has_end

Descrição:
Verifica se todas as aspas (simples ou duplas) na string
possuem um par de fechamento correspondente.

Parâmetros:
- char *str: A string a ser verificada.

Retorno:
- int: NOTERROR (0) se todas as aspas têm um par de fechamento,
ou ERROR (1) se alguma aspa não tem fechamento.
*/

int all_quotes_has_end(char *str)
{
    int i;
    int flag;

    i = -1;
    flag = 0;
    while (str[++i])
    {
		if ((str[i] == 34 || str[i] == 39) && flag == 0)
			flag = str[i];
		else if (str[i] == flag)
			flag = 0;
    }
	if (flag == 0)
		return (NOTERROR);
	return (ERROR);
}