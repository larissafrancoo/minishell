#include "minishell.h"

static void	ft_end(t_env *env, t_shell *sh)
{
	ft_shclean(sh);
	ft_arr_free(env->var_list);
	free(env->pwd);
	free(env);
}

static int ft_compare_with_limit(char *arg, int i, int len, int sign)
{
    char *limit;
    int j;

    if (sign == 1) {
        limit = "9223372036854775807";  // Limite para números positivos
    } else {
        limit = "9223372036854775808";  // Limite para números negativos
    }
    j = -1;
    while (++j < len)
    {
        if (arg[i + j] > limit[j])
            return 1;
        if (arg[i + j] < limit[j])
            return 0;
    }
    return 0;  // Se for igual, não há overflow
}

static int ft_is_overflow(char *arg)
{
    int sign;
    int i;
    int len;

    i = 0;
    sign = 1;
    if (arg[i] == '-' || arg[i] == '+')
    {
        if (arg[i] == '-')
            sign = -1;
        i++;
    }
    while (arg[i] == '0')
        i++;
    if (arg[i] == '\0')
        return 0;
    len = ft_strlen(arg + i);
    if (len > 19)
        return 1;
    return (ft_compare_with_limit(arg, i, len, sign));
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
	if (ft_size(args) == 2)
	{
		// Verifica se o argumento não é numérico ou se há overflow
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
	else if (ft_size(args) > 2)
	{
		ft_printf("exit: too many arguments\n");
		return ;
	}
	ft_end(env, shell);
	exit(status_g);
}
