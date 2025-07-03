int	ft_is_prime(int nb)
{
	long long int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long long int	i;

	i = nb;
	if (i < 2)
		return (2);
	while (ft_is_prime(i) == 0)
		i++;
	return (i);
}
