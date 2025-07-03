/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:07:53 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/01 20:04:42 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		check_num(char c, char *str);
int		ft_baselen(char *str);
int		ft_intlen(int n, int bsize);

char	*ft_itoa(int nb, char *base, int bsize)
{
	int		i;
	long	n;
	char	*arr;

	if (bsize < 2)
		return (NULL);
	i = 0;
	n = (long)nb;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	i += ft_intlen(n, bsize);
	arr = malloc(sizeof(char) * i + 1);
	arr[i] = '\0';
	while (i)
	{
		arr[i - 1] = base[n % bsize];
		n /= bsize;
		i--;
	}
	if (nb < 0)
		arr[0] = '-';
	return (arr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	minus;
	int	size;
	int	i;

	i = 0;
	minus = 1;
	nb = 0;
	size = ft_baselen(base);
	if (size < 2)
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = minus * -1;
		i++;
	}
	while (check_num(str[i], base) >= 0)
	{
		nb = nb * size + check_num(str[i], base);
		i++;
	}
	return (nb * minus);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*arr;
	int		n;
	int		bsize;

	bsize = ft_baselen(base_to);
	n = ft_atoi_base(nbr, base_from);
	arr = ft_itoa(n, base_to, bsize);
	return (arr);
}
/* int main()
{
		printf("======ex04======\n");
		char str[4] = "101";
		char base_form[10] = "01";
		char base_to[10] = "0123456789";
		printf("%s\n", ft_convert_base(str, base_form, base_to));
} */ 
 int		main(void)
{
	printf("result : $%s$\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("result : $%s$\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01"));
	printf("result : $%s$\n", ft_convert_base("101", "01", "0123456789"));
	printf("result : $%s$\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
} 



