/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_arr_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:25:43 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/31 18:40:01 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int	check(int row, int *arr)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (arr[i] == arr[row])
			return (0);
		if (row - i == arr[row] - arr[i] || row - i == arr[i] - arr[row])
			return (0);
		i++;
	}
	return (1);
}

void	output(int *arr)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	recur(int row, int *num, int *arr)
{
	int	column;

	if (row == 10)
	{
		*num += 1;
		output(arr);
		return ;
	}
	column = 0;
	while (column < 10)
	{
		arr[row] = column;
		if (check(row, arr))
			recur(row + 1, num, arr);
		column++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		num;
	int		arr[10];

	num = 0;
	recur(0, &num, arr);
	return (num);
}

int main()
{
	printf("%d", ft_ten_queens_puzzle());
}
