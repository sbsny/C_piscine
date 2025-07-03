#include <stdlib.h>

int	str_len(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	return (i);
}

int	str_cat(int n, char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[n + i] = src[i];
		i++;
	}
	return (n + i);
}

void	final_cat(int size, char *str_join, char **strs, char *sep)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = str_cat(j, str_join, strs[i]);
		if (i < size - 1)
			j = str_cat(j, str_join, sep);
		i++;
	}
	str_join[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_join;
	int		i;
	int		len;

	i = 0;
	if (size == 0)
	{
		str_join = (char *)malloc(sizeof(char));
		return (str_join); // '\0' 값을.
	}
	len = str_len(sep) * (size - 1);
	while (i < size)
	{
		len += str_len(strs[i]);
		i++;
	}
	str_join = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_join)
		return (NULL);
	final_cat(size, str_join, strs, sep);
	return (str_join);
}
