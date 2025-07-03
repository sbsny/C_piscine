
#include <stdlib.h>
#include <stdio.h>

int	ft_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i++])
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_cw(char *str, char *charset)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (ft_sep(str[i], charset))
			i++;
		while (!(ft_sep(str[i], charset)) && str[i])
			i++;
		if ((ft_sep(str[i], charset) || str[i]) && !(ft_sep(str[i - 1],
					charset)))
			w++;
		i++;
	}
	return (w);
}

char	*ft_strdup(char *src, char *charset)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (src[i] && !(ft_sep(src[i], charset)))
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (src[j] && j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		w;
	char	**dest;

	w = ft_cw(str, charset);
	dest = malloc(sizeof(char *) * (w + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	dest[w] = NULL;
	while (i < w)
	{ 
		while (ft_sep(str[j], charset))
			j++;
		if (!(ft_sep(str[j], charset)) && str[j])
			dest[i] = ft_strdup(&str[j], charset);
		while (!(ft_sep(str[j], charset)) && str[j])
			j++;
		i++;
	}
	return (dest);
}

 int	main(void)
{
	char	*megastring;
    char **tab;
	int	i;
	megastring = "_heo$my$##cl=fr nd!";
    tab = ft_split(megastring, " ! _=$+#@#");
    i = 0;
    while (tab[i])
        printf(">%s< \n", tab[i++]);
    return (0);
} 

// https://klkl0.tistory.com/48, https://dojang.io/mod/page/view.php?id=319




#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (is_charset(str[i + 1], charset) == 1
			&& is_charset(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	copy_str(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_charset(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	excute_split(char **arr, char *str, char *charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_charset(str[i + j], charset) == 0)
				j++;
			arr[word] = (char *)malloc(sizeof(char) * (j + 1));
			copy_str(arr[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		word_count;

	word_count = count_words(str, charset);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	excute_split(arr, str, charset);
	arr[word_count] = 0;
	return (arr);
}