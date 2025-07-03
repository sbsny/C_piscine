/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:18:49 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/03 23:21:02 by seonyun          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *result;

	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (0);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}




int		print_next_num(int n)
{
	n += 1;
	return (n);
}

int		main(void)
{
	int tab[] = {1, 3, 5, 7, 9};
	int i;
	int *result = ft_map(tab, 5, &print_next_num);
	
	i = 0;
	while (i < 5)
	{
		printf("%d ", result[i]);
		i++;
	}
	return (0);
}