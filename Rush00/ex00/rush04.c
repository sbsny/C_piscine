/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:57:19 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/21 18:44:38 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	check(int x, int y) // x, y가 음수거나 0이면 return 0으로 실행되지 않게. 1이 되면 실행되게 <-- 예외처리 함수.
{
	if (x <= 0 || y <= 0)
	{
		return (0);
	}
	return (1);
}

void	print(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i == x && j == y && i != 1 && j != 1))  // 뒤에 i j가 1이 안 되는 이유는 A가 x 1행에 더 있으면 안 되고 y 1열에 A가 있으면 안 된다.
		ft_putchar('A');
	else if ((i == 1 && j == y) || (i == x && j == 1)) // C가 있는 규칙은 1열의 맨 끝에 위치하는 것과 1행 x의 맨 끝에 위치. 
		ft_putchar('C');
	else if (i == 1 || j == 1 || i == x || j == y) // B가 있는 규칙은 위에 if가 다 안 되면 나오면 된다. 대신에 공백이 있는 중간 사이에 있으면 안 돼서 i가 x랑 같거나 y가 j랑 같아야 한다. i가 1이면 뭐든 게 B가 올 수 있음. 
		ft_putchar('B');						   // i가 x행이거나 y행에만 올 수 있음. 공백이 있는 곳에 위치하면 안 되기 때문
	else   										   // 다 해당하지 않으면 공백으로 출력
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
		while (j <= y)       // y는 세로 열, x는 가로 행 // i j는 임의로 찾으려는 rush(i, j) 결과의 i, j
		{
			i = 1;                    
			while (i <= x)
			{
				print(x, y, i, j);
				i++;
			}
			ft_putchar('\n');             // j 안의 i이기 때문에 y 1열에서 x 1행의 값을 먼저 다 출력하고 그 다음 y의 2열로 넘어가게 '\n' new line이 여기 위치.
			j++;
		}
	}
}
