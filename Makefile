NAME	=	minishell

CC		= 	cc

CFLAGS	=	-Wall -Wextra -Werror -g

RM		=	rm -f

LIBRARY	=	./libft/

SRCS	=	./src/1_start_function.c\
			./src/2_env.c\
			./src/3_utils_1.c\
			./src/4_check_functions.c\
			./src/4_check_functions2.c\
			./src/5_split_pipe_process.c\
			./src/5_split_pipe_process2.c\
			./src/6_tokenizator_process1.c\
			./src/6_tokenizator_process2.c\
			./src/7_free_function.c\
			main.c\

all: $(NAME)

libft:
	cd $(LIBRARY) && $(MAKE) bonus && cp -v libft.a ../

minishell: libft
	cc -g $(SRCS) libft.a -lreadline -o $(NAME)

run: re
	./$(NAME)

val: re
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=supressions.supp --track-fds=yes ./$(NAME)

norm:
	@-norminette -R CheckForbiddenSourceHeader

clean:
	cd $(LIBRARY) && $(MAKE) clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) libft.a
	cd $(LIBRARY) && $(MAKE) fclean

re:	fclean all

.PHONY:	all clean fclean re libft