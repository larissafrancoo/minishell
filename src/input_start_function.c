#include "../include/minishell.h"

void    start_function(t_env *env_list)
{
    char *rd_input;
    int ret_dtok;

    while (1)
    {
		rd_input = readline("\nnickname@123:~/um/caminho/qualquer$ ");
		add_history(rd_input);

		if (strcmp(rd_input, "exit") == 0)
		{
			free(rd_input);
			break ;
		}
		else if (strcmp(rd_input, "env") == 0)
		{
			ret_dtok = print_env(env_list);
			if (!ret_dtok)
			{
			    free_env(env_list);
				printf("ERRO NA ENV\n");
			}
		}
		else if (strcmp(rd_input,"pwd") == 0)
		{
			ret_dtok = ft_pwd();
			if (!ret_dtok)
			{
			    free_env(env_list);
				printf("ERRO NA PWD\n");
			}
		}
        ret_dtok = do_tokens(rd_input);
		if (ret_dtok)
		{
			rl_on_new_line();
			if (ret_dtok == ERROR_QUOTE)
				rl_replace_line("Aspas sem fechamento.\n", 0);
			else if (ret_dtok == ERROR_WORD)
				rl_replace_line("Erro na alocação de palavras.\n", 0);
			rl_redisplay();
		}
        free(rd_input);
    }
	rl_clear_history();
	printf("\nPrograma encerrado.\n");
}