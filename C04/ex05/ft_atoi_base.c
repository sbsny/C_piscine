/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:59:27 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/28 16:28:11 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check(char *base)
{
	int	len;
	int	a;
	int	b;

	a = 0;
	len = ft_len(base);
	if (len == 0 || len == 1)
		return (0);
	while (base[a])
	{
		b = a + 1;
		if (base[a] == 32 || base[a] == '-'
			|| base[a] == '+' || (base[a] >= 9 && base[a] <= 13))
			return (0);
		while (base[b])
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	if_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	first(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	n;

	i = 0;
	n = 0;
	minus = 1;
	if (!check(base))
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = minus * -1;
		i++;
	}
	while (if_base(str[i], base))
	{
		n = n * ft_len(base) + first(str[i], base);
		i++;
	}
	return (n * minus);
}
