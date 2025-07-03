/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:19:39 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/03 23:21:54 by seonyun          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}


int have_a(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	char **tab = (char **)malloc(sizeof(char *) * 5);

	tab[0] = "oh";
	tab[1] = "hh";
	tab[2] = "sw";
	tab[3] = "eae";
	tab[4] = 0;
	printf("%d\n", ft_any(tab, &have_a));
	return (0);
}