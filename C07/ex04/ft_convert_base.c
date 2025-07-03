#include <stdlib.h>
#include <stdio.h>

int		ft_basewalk(char c, char *str);
int		ft_baselen(char *str);
int		ft_intlen(int n, int bsize);

char	*ft_itoa(int nb, char *base, int bsize)
{
	int		i;
	long	n;
	char	*dest;

	if (bsize < 2)
		return (NULL);
	i = 0;
	n = (long)nb;
	if (n < 0 && ++i)
		n *= -1;
	i += ft_intlen(n, bsize);
	dest = malloc(sizeof(char) * i + 1);
	dest[i] = '\0';
	while (i)
	{
		dest[--i] = base[n % bsize];
		n /= bsize;
	}
	if (nb < 0)
		dest[0] = '-';
	return (dest);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	minus;
	int	size;

	minus = 0;
	nb = 0;
	size = ft_baselen(base);
	if (size < 2)
		return (0);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			minus++;
	while (ft_basewalk(*str, base) >= 0)
		nb = nb * size + ft_basewalk(*str++, base);
	if (minus % 2 != 0)
		nb *= -1;
	return (nb);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*dest;
	int		bsize;

	bsize = ft_baselen(base_to);
	n = ft_atoi_base(nbr, base_from);
	dest = ft_itoa(n, base_to, bsize);
	return (dest);
}

/* int		main(void)
{
	printf("result : $%s$\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("result : $%s$\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01"));
	printf("result : $%s$\n", ft_convert_base("10001", "01", "0123456789"));
	printf("result : $%s$\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
}