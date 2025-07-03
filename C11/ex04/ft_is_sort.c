/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:23:15 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 02:06:54 by seonyun          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	result;
	int gap;

	i = 0;
	gap = 0;
	while (i < length - 1)
	{
		result = f(tab[i], tab[i + 1]);
		if (result == 0)
		{
			i++;
			continue;
		}
		if (gap == 0)
			gap = result;
		if ((gap > 0 && result < 0) || (gap < 0 && result > 0))
			return (0);
		i++;
	}
	return (1);
}



int		ft_compare(int n1, int n2)
{
	return (n1 - n2);
}

int main(void)
{
	int sorted1[] = {10, 30, 56, 1235, 6546, 10345};
	int sorted2[] = {7, 7, 7, 7, 6, 6, 6, 6, 5, 5, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1};
	int not_sorted1[] = {10, 30, 56, 3, 10345, 1235, 6546};
	int not_sorted2[] = {6546, 1235, 10345, 3, 56, 30, 10};
	printf("%d\n", ft_is_sort(sorted1, 6, &ft_compare));
	printf("%d\n", ft_is_sort(sorted2, 26, &ft_compare));
	printf("%d\n", ft_is_sort(not_sorted1, 7, &ft_compare));
	printf("%d\n", ft_is_sort(not_sorted2, 7, &ft_compare));
	return (0);
}