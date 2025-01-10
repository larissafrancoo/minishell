NAME	=	minishell

CC		= 	cc

CFLAGS	=	-Wall -Wextra -Werror -g

RM		=	rm -f

LIBRARY	=	./libft/

SRCS	=	./src/input_checker_functions.c\
			./src/input_tokenizator.c\
			./src/input_start_function.c\
			./src/env_function.c\
			./src/env_utils.c\
			./src/split_function.c\
			./src/split_utils.c\
			./src/main.c\

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