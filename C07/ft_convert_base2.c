/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:08:23 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/01 22:18:40 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(long n, int bsize)
{
	if (n < bsize)
		return (1);
	return (1 + ft_intlen(n / bsize, bsize));
}

int	check_num(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		else if (base[i + 1] && check_num(base[i], base + i + 1) >= 0)
			return (0);
		i++;
	}
	return (i);
}
