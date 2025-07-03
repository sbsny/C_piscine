/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:22:05 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/06 22:53:20 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			num++;
		i++;
	}
	return (num);
}
