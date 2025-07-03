/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:18:14 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/05 18:40:08 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
        i++;
	}
}


void	ft_putnbr(int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
}

int		main(void)
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	ft_foreach(tab, 13, *ft_putnbr);
	return (0);
}
