/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:22:05 by seonyun           #+#    #+#             */
/*   Updated: 2022/06/06 12:17:12 by seonyun          ###   ########.fr       */
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
	int length = 5;
	char **tab = (char **)malloc(sizeof(char *) * (length + 1));

	tab[0] = "oh";
	tab[1] = "haha";
	tab[2] = "sw";
	tab[3] = "eae";
//	tab[4] = 0;
	printf("%d\n", ft_count_if(tab, length, &have_a));
	return (0);
}