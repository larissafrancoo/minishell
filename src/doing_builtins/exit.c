#include "minishell.h"

static void	ft_end(t_env *env, t_shell *sh)
{
	ft_shclean(sh);
	ft_arr_free(env->var_list);
	free(env->pwd);
	free(env);
}

static int ft_is_overflow(char *arg)
{
    long long num;
    int sign;
    int i;
    int len;
    char *limit;
    int j;

    i = -1;
    sign = 1;
    limit = "9223372036854775807";
    if (arg[++i] == '-' || arg[i] == '+')
    {
        if (arg[i] == '-')
            sign = -1;
    }
    while (arg[i] == '0')
        i++;
    if (arg[i] == '\0')
        return 0;
    len = ft_strlen(arg + i);
    if (len > 19)
        return 1;
    if (sign == 1)
        limit = "9223372036854775808";
    j = -1;
    while(++j < len)
    {
        if (arg[i + j] > limit[j])
            return 1;
        if (arg[i + j] < limit[j])
            return 0;
    }
    return 0;
}

static int	ft_is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_exit(char **args, t_env *env, t_shell *shell)
{
	unsigned char	ret;

	status_g = 0;
	ft_printf("exit\n");
	if (ft_arr_size(args) == 2)
	{
		if (ft_is_all_digit(args[1]) || ft_is_overflow(args[1]))
		{
			ft_printf("exit: %s: numeric argument required\n", args[1]);
			status_g = 2;
		}
		else
		{
			ret = ft_atolli(args[1]);
			status_g = ret;
		}
	}
	else if (ft_arr_size(args) > 2)
	{
		ft_printf("exit: too many arguments\n");
		return ;
	}
	ft_end(env, shell);
	exit(status_g);
}