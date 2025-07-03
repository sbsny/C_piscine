#include <unistd.h>

char	*ft_remove_blanks(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	return (str + i);
}

char	*ft_remove_operators(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		else
			break ;
	}
	return (str + i);
}

int	ft_find_operator(char *str)
{
	int	minus;
	int	i;

	i = 0;
	minus = 1;
	while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				minus = minus * -1;
			i++;
		}
	return (minus);
}

int	ft_atoi(char *str)
{
	int		minus;
	int		result;
	char	*cmp;
	int		i;

	i = 0;
	result = 0;
	cmp = str;
	minus = ft_find_operator(cmp);
	cmp = ft_remove_blanks(cmp);	
	cmp = ft_remove_operators(cmp);
	while (cmp[i])
	{
		if (cmp[i] < '0' || cmp[i] > '9')
			break ;
		result *= 10;
		if (minus < 0)
			result -= cmp[i] - '0';
		else
			result += cmp[i] - '0';
		i++;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		c = -(nb % 10) + '0';
		if (nb / 10 != 0)
			ft_putnbr(-(nb / 10));
	}
	else if (nb / 10 == 0)
	{
		c = nb + '0';
	}
	else
	{
		c = (nb % 10) + '0';
		ft_putnbr(nb / 10);
	}
	write(1, &c, 1);
}