/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:23:15 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 13:05:56 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int temp;
	int diff;

	i = 0;
	diff = 0;
	while (i < length - 1)
	{
		temp = f(tab[i], tab[i + 1]);
		if (temp == 0)
		{
			i++;
			continue;
		}
		if (diff == 0)
			diff = temp;
		if ((diff > 0 && temp < 0) || (diff < 0 && temp > 0))
			return (0);
		i++;
	}
	return (1);
}

if ((gap > 0 && value < 0) || (gap < 0 && value > 0))

int		diff_num(int n1, int n2)
{
	return (n1 - n2);
}

int		main(void)
{
	int length = 6;
	int tab[] = {0, 1, 2, 3, 4, 5};
	int tab1[] = {0, -1, -2, -3, -4, -5};
	int tab2[] = {0, 1, 2, 3, -4, 5};
	int tab3[] = {0, 1, 1, 1, 1, 1};

	printf("%d\n", ft_is_sort(tab, length, &diff_num));
	printf("%d\n", ft_is_sort(tab1, length, &diff_num));
	printf("%d\n", ft_is_sort(tab2, length, &diff_num));
	printf("%d\n", ft_is_sort(tab3, length, &diff_num));
	return (0);
}