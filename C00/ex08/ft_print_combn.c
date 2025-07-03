/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:31:34 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/21 21:51:14 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *nums, int n)
{
	if (nums[0] == 10 - n + '0')
		write(1, nums, n);
	else
		write(1, nums, n + 2);
}

void	comb(int n, int count, char *nums)
{
	int index;

	if (count == n)
	{
		print(nums, n);
		return ;
	}
	index = 0;
	while (index < 10)
	{
		if (count == 0 || nums[count - 1] < index + 48)
		{
			nums[count] = index + '0';
			comb(n, count + 1, nums);
		}
		index++;
	}
}

void	ft_print_combn(int n)
{
	char nums[n + 2];

	nums[n] = ',';
	nums[n + 1] = ' ';
	comb(n, 0, nums);
}







#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *range, int n)
{
	int	i;
	int	display;

	display = 1;
	i = 0;
	while (++i < n)
		if (range[i - 1] >= range[i])
			display = 0;
	if (!display)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(range[i] + 48);
	if (range[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	range[10];

	if (n > 10 || n < 0)
		return ;
	i = -1;
	while (++i < n)
		range[i] = i;
	while (range[0] <= (10 - n) && n >= 1)
	{
		print(range, n);
		if (n == 10)
			break ;
		range[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (range[i] > 9)
			{
				range[i - 1]++;
				range[i] = 0;
			}
		}
	}
}