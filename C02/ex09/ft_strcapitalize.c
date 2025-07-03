/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:04:46 by seonyun           #+#    #+#             */
/*   Updated: 2022/05/23 13:00:20 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (str[i])
	{
		if (ft_alpha(str[i]))
		{
			if (first && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!first && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			first = 0;
		}
		else
			first = 1;
		i++;
	}
	return (str);
}
