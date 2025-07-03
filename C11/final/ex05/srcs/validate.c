int	ft_is_operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '/'
		|| ch == '*' || ch == '%')
		return (1);
	return (0);
}

int	ft_is_valid_op(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (i != 1)
		return (0);
	if (!ft_is_operator(arg[0]))
		return (0);
	return (1);
}