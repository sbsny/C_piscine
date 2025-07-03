/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:18:49 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 13:07:50 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*val;

	val = (int *)malloc(sizeof(int) * length);
	if (!val)
		return (0);
	i = 0;
	while (i < length)
	{
		val[i] = f(tab[i]);
		i++;
	}
	return (val);
}
