/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:49:26 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/05 01:44:21 by seonyun          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_num(char *str, char *charset)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			num++;
			while (str[i] && !check(str[i], charset))
				i++;
		}
	}
	return (num);
}

char	*ft_strdup(char *str, char *charset)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] && !check(str[i], charset))
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && !check(str[i], charset))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		j;
	int		i;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (word_num(str, charset) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			arr[j] = ft_strdup(&str[i], charset);
			j++;
			while (str[i] && !check(str[i], charset))
				i++;
		}
	}
	arr[j] = 0;
	return (arr);
}
