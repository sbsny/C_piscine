/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:15:06 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/21 22:44:06 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	rev;
	int	i;

	i = 0;
	rev = size - 1;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[rev];
		tab[rev] = tmp;
		i++;
		rev--;
	}
}
