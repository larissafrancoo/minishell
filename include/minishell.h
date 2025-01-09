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
	t_env_node *head;
	t_env_node *tail;
}	t_env;

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
	char *piece;
	t_token_type type;
	struct s_token *next;
} t_token;

#endif
