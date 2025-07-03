/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:25:21 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/06 12:17:16 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char *tab[])
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[j], tab[i]) < 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}



#include <stdio.h>
void	ft_sort_string_tab(char *tab[]);
int main()
{
	char *tab[4];
	tab[0] = "coucou";
	tab[1] = "bonjour";
	tab[2] = "bondour";
	tab[3] = NULL;

	ft_sort_string_tab(tab);
	int i = 0;
	while (tab[i])
	{
		printf("%s ", tab[i++]);
	}
	return (0);
}