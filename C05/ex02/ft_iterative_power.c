int	ft_iterative_power(int nb, int power)
{
	int	val;

	val = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		val *= nb;
		power--;
	}
	return (val);
}
