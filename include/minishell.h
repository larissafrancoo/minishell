#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_SIZE 1024

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <linux/limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef enum e_token_type {
	CMD = 2,
	ARG = 3,
	REDIR = 4,
	PIPE = 5,
	REDIR_ARG = 6
}	t_token_type;

typedef struct s_env
{
	char	*key;
	char	*str;
	struct s_env	*next;
}			t_env;

typedef struct s_token
{
	char	*str;
	t_token_type	type;
	struct s_token	*next;
}			t_token;

enum
{
	ERROR = 0,
	NOTERROR = 1,
	ERROR_QUOTE = 2,
	ERROR_WORD = 3,
};

//split_function
char	*word_between_spaces(char *str, int idx);
void	split_free(char **str, size_t o);
char    **mod_split_input(char *str);
int		has_spaces(char *str);

//split_utils
int is_space(int c);
int find_next_char(char *str, int idx);
size_t  word_count(char *str);
int all_quotes_has_end(char *str);

//input_start_function
void    start_function(t_env *env_list);

//input_checker_functions
int input_check(char *str);

//input_tokenizato
t_token	*token_lstlast(t_token *lst);
void	token_lstadd_back(t_token **lst, t_token *new);
void	free_tokens(t_token *list);
int check_type_input(char *str, int prev);
void add_type_in_the_list(t_token **lst);
t_token	*token_lstnew(char *first_str);
t_token *tokenizator(char *rd_input, t_token *token_list);
int do_tokens(char *rd_input);

//env_functions
static int	first_equal(char *str);
t_env	*my_env_lst(char **ev, t_env *env_list);

//env_utils
t_env	*my_lstlast(t_env *lst);
void	my_lstadd_back(t_env **lst, t_env *new);
t_env	*env_lstnew(char *first_str, char *second_str);
void	free_env(t_env *list);

//env
int	print_env(t_env *env_list);

//pwd
int	ft_pwd(void);

#endif
