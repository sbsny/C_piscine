/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:46:04 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 10:55:52 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	final_check(char op)
{
	if (op == '+' || op == '-' || op == '*'
		|| op == '/' || op == '%')
		return (1);
	return (0);
}

int	if_op(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 1)
		return (0);
	if (!final_check(argv[0]))
		return (0);
	return (1);
}
