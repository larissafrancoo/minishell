#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_SIZE 1024
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/wait.h>
# include <linux/limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <stdbool.h>


typedef enum e_token_type
{
	CMD = 2,
	CMD_ARG,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
	IN_ARG,
	OUT_ARG,
	APPEND_ARG,
	HEREDOC_ARG,
	PIPE,
} t_token_type;

typedef struct s_intro
{
	char *input;
	t_env env_list;
	t_cmd **cmds;
	int	pipe_fd[2];
}	t_intro;

typedef struct s_env
{
	char	*key;
	char	*value;
	t_env_node *head;
	t_env_node *tail;
	struct s_env	*next;
	struct s_env	*prev;
}			t_env;

typedef struct s_env_node
{
	struct s_env_node *prev;
	char *key;
	char *value;
	struct s_env_node *next;
}	t_env_node;

typedef struct s_cmd
{
	char *cmd;
	int fd_in;
	int fd_out;
	pid_t pid;
	t_token *token_list;
} t_cmd;

typedef struct s_token
{
	struct s_token *prev;
	char	*token;
	char	*first_cmd;
	char	cmd;
	char	*path;
	char *piece;
	t_token_type type;
	struct s_token	*next;
}			t_token;

typedef struct  s_pid
{
	pid_t	pid;
	struct s_pid	*next;
}	t_pid;

typedef struct s_shell
{
	char	**argv;			
	t_env	*env;
	t_pid	*pid;		
	t_cmd	**cmd;
	int		fd[2];			
}	t_shell;

enum
{
	ERROR = 0,
	NOTERROR = 1,
	ERROR_QUOTE = 2,
	ERROR_WORD = 3,
}

enum e_fd
{
	IN = 0,
	OUT = 1
};


void start_function(t_intro *shell, char **ev);
int str_space(char *str);
int char_space(int c);
int check_input(char *input);
int error_input(char *input);
int check_quotes(char *str);
int check_pipes(char *str);
int print_error(t_token_type type);
void change_flag(int c, int *single_flag, int *double_flag);
int handle_quotes(char *str, int *i, int *flag);
int has_a_pair(const char *str);
int check_operators(char *str);
int isop(const char *str);
int char_redirect(char c);
void get_env(t_env *list, char ** ev);
int vetor_size(char **ev);
char *get_env_content(char *ev, int sig);
t_env_node *new_env_node(char *key, char *value);
void env_addback(t_env *list, t_env_node *new);
void free_env_error(t_env **list, char **key, char **value);
void free_env(t_env *list);
void	free_all_cmds(t_cmd ***cmds);
void    free_tokens(t_token *token_list);
void	go_minibash(t_intro *shell);

#endif
