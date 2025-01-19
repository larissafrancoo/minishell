#include "minishell.h"

int	ft_size(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

long long int	ft_atolli(const char *str)
{
	long long int	result;
	int				sign;
    int             i;

    i = 0;
	result = 0;
    sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
    
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += sign * (str[i] - '0');
		i++;
	}
	return (result);
}