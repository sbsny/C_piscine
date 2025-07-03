/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:46:43 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 12:49:01 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

int	calculate(int i, int j, char op)
{
	int	(*point[5])(int, int);

	point[0] = &add;
	point[1] = &sub;
	point[2] = &div;
	point[3] = &mul;
	point[4] = &remainde;
	if (op == '+')
		return (point[0](i, j));
	else if (op == '-')
		return (point[1](i, j));
	else if (op == '/')
		return (point[2](i, j));
	else if (op == '*')
		return (point[3](i, j));
	else if (op == '%')
		return (point[4](i, j));
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	op;

	if (argc == 4)
	{	
		if (!if_op(argv[2]))
			write(1, "0\n", 2);
		else
		{
			i = ft_atoi(argv[1]);
			op = argv[2][0];
			j = ft_atoi(argv[3]);
			if (op == '/' && j == 0)
				write(1, "Stop : division by zero\n", 24);
			else if (op == '%' && j == 0)
				write(1, "Stop : modulo by zero\n", 22);
			else
			{
				ft_putnbr(calculate(i, j, op));
				write(1, "\n", 1);
			}
		}
	}
}
