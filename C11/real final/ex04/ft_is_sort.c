/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:23:15 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 16:10:17 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	gap;
	int	value;

	i = 0;
	gap = 0;
	while (i < length - 1)
	{
		value = f(tab[i], tab[i + 1]);
		if (value == 0)
		{
			i++;
			continue ;
		}
		if (gap == 0)
			gap = value;
		if ((gap < 0 && value > 0) || (gap > 0 && value < 0))
			return (0);
		i++;
	}
	return (1);
}
