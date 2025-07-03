/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:22:05 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/07 01:40:15 by seonyun          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

int have_a(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	char *tab1[] = {
		"Hello World!!",
		"42SEOUL  42SEOUL",
		"HelloAllAppAll",
		"\t\t\t\t\t",
		"DiffKO:(",
		"Diff OK :D",
		"Diff OK :D",
		"Diff OK :D",
		"Diff OK :D",
		"Diff OK :D",
		"Diff OK :D"
	};
	printf("tab1 result=%d\n", ft_count_if(tab1, 11, &have_a));
}