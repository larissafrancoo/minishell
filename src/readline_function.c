#include "../include/minishell.h"

void    readline_function(t_env *env_list, t_token *tokens)
{
    char *rd_input;
    int ret_dtok;
	int ret_parser;

    while (1)
    {
		rd_input = readline("\nnickname@123:~/um/caminho/qualquer$ ");
		add_history(rd_input);
		ret_parser = parser_home(rd_input, tokens, env_list);
		if (ret_parser)
		{
			rl_on_new_line();
			if (ret_parser == ERROR_QUOTE)
				rl_replace_line("Aspas sem fechamento.\n", 0);
			else if (ret_parser == ERROR_WORD)
				rl_replace_line("Erro na alocação de palavras.\n", 0);
			else if (ret_parser == EXIT_SUCCESS)
			{
				free(rd_input);
				break ;
			}
			rl_redisplay();
		}
        free(rd_input);
    }
	rl_clear_history();
	printf("\nPrograma encerrado.\n");
}