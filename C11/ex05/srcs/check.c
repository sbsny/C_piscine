int	ft_is_operator(char op)
{
	if (op == '+' || op == '-' || op == '/'
		|| op == '*' || op == '%')
		return (1);
	return (0);
}

int	ft_is_valid_op(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 1)
		return (0);
	if (!ft_is_operator(argv[0]))
		return (0);
	return (1);
}