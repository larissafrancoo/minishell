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

//readline_function
void    readline_function(t_env *env_list, t_token *tokens);

//parser_p1
int parser_home(char *input, t_token *token_lst, t_env *env_lst);

//input_checker_functions
int input_check(char *str);

//input_tokenizator
t_token	*token_lstlast(t_token *lst);
void	token_lstadd_back(t_token **lst, t_token *new);
void	free_tokens(t_token *list);
int check_type_input(char *str, int prev);
void add_type_in_the_list(t_token **lst);
t_token	*token_lstnew(char *first_str);
t_token *tokenizator(char *rd_input, t_token *token_list, t_env *env_lst);
int do_tokens(char *input, t_token *tokens, t_env *env_lst);

//env_functions
static int	first_equal(char *str);
t_env	*my_env_lst(char **ev, t_env *env_list);

//env_utils
t_env	*my_lstlast(t_env *lst);
void	my_lstadd_back(t_env **lst, t_env *new);
t_env	*env_lstnew(char *first_str, char *second_str);
void	free_env(t_env *list);

//expansor
char *expander_the_input(char *input, t_env *env_lst);
int expansor(t_token *token_lst, t_env *env_lst);

//expansor_utils
char *replace_the_part(char *str, t_env *env_lst);
char *get_first_part(char *str, int idx);
char *get_the_key(char *str, int idx, t_env *env_lst);
char *get_final_part(char *str, int idx);
char *join_the_parts(char *p1, char *p2, char *p3);

//matriz_builtins
int check_builtins(t_token *token_lst, t_env *env_lst);

//env
int	print_env(t_env *env_list);

//pwd
int	ft_pwd(void);

#endif
