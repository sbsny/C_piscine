/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:57:08 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/21 19:00:37 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	check(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return (0);
	}
	return (1);
}

void	print(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i == 1 && j == y))           // 여기서는 A가 (1,1) 위치에만 있거나 y열의 맨 마지막 1행에만 있어서 i == 1과 j == y 둘 다 충족해야 함.
		ft_putchar('A');
	else if ((i == x && j == 1) || (i == x && j == y))        // C는 1행의 맨 마지막에 위치하거나 y열에서 마지막 행에만 위치하는 규칙.
		ft_putchar('C');
	else if (i == 1 || j == 1 || i == x || j == y)          // B가 1열이거나 1행이면 위에를 제외하고 다 B가 출력되고, rush의 x랑 같거나 y랑 같으면 또 B를 출력. 왜냐면 가운데는 비우기 공백으로 비우기 위해서.
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (check(x, y))
	{
		while (j <= y)
		{
			i = 1;
			while (i <= x)
			{
				print(x, y, i, j);
				i++;
			}
			ft_putchar('\n');
			j++;
		}
	}
}
