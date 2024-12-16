#include "../../include/minishell.h"

int ft_pwd(void)
{
    char pwd[PATH_MAX];

    if (!getcwd(pwd, PATH_MAX))
    {
        printf("erro na pwd\n");
        return (0);
    }
    printf("%s\n", getcwd(pwd, PATH_MAX));
    return (1);
}