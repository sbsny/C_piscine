#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*a;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	a = (int *)malloc(sizeof(a) * (max - min));
	if (!a)
		return (-1);
	while (min < max)
	{
		a[i] = min;
		i++;
		min++;
	}
	*range = a;
	return (i);
}
