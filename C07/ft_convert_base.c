/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:07:53 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/01 23:13:30 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_num(char c, char *str);
int		ft_intlen(int n, int bsize);
int		ft_baselen(char *str);

char	*ft_itoa(int nb, char *base, int bsize)
{
	int		i;
	char	*arr;
	long	n;

	i = 0;
	n = (long)nb;
	if (bsize < 2)
		return (NULL);
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
		arr[--i] = base[n % bsize];
		n /= bsize;
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
	int		bsize1;

	bsize = ft_baselen(base_to);
	bsize1 = ft_baselen(base_from);
	if (bsize1 < 2)
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	arr = ft_itoa(n, base_to, bsize);
	return (arr);
}
