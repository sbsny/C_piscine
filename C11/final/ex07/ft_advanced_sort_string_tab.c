/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:26:00 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/06 12:17:17 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char *tab[], int (*cmp)(char *, char *))
{
	int		is_sorted;
	int		j;
	char	*temp;

	is_sorted = 0;
	while (!is_sorted)
	{
		j = 0;
		is_sorted = 1;
		while (tab[++j])
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
				is_sorted = 0;
			}
	}
}



int main()
{
	char *tab[10] = {"YFxVpy","6","hvPi0cDj9lT","OalhZkr6ntJm","YKm9DBv4xVnp","LrOftTgU","JKdoTWZBL3","0ubxom","7PY4", 0};
	ft_advanced_sort_string_tab(tab, ft_strcmp);
	int i = 0;
	while (tab[i])
	{
		printf("tab[%d]: %s\n", i, tab[i]);
		i++;
	}
	char *tab2[10] = {"YFxVpy","6","hvPi0cDj9lT","OalhZkr6ntJm","YKm9DBv4xVnp","LrOftTgU","JKdoTWZBL3","0ubxom","7PY4", 0};
	printf("\n");
	ft_sort_string_tab(tab2);
	i = 0;
	while (tab2[i])
	{
		printf("tab2[%d]: %s\n", i, tab2[i]);
		i++;
	}
	return (0);
}