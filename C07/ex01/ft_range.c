#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	i;

	i = 0;
	if (min >= max)
	{
		a = NULL;
		return (a);
	}
	a = (int *)malloc(sizeof(a) * (max - min));
	if (!a)
		return (NULL);
	while (min < max)
	{
		a[i] = min;
		min++;
		i++;
	}
	return (a);
}
