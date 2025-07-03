/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:26:00 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 16:47:41 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		sort_done;
	char	*t;

	sort_done = 1;
	while (sort_done)
	{
		sort_done = 0;
		i = 1;
		while (tab[i])
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				t = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = t;
				sort_done = 1;
			}
			i++;
		}
	}
}
