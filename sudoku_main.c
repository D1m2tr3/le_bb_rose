int	valid_block(char **tab, int b);


int 	error(void)
{
	write(1, "Erreur\n", 7);
	return (1);
}

int	main(int ac, char ** av)
{
	if (ac != 10 || valid_size(tab) || valid_line(av, 1) || valid_column(av, 0)
		|| valid_block(av, 0))
		return (error());
	resolver(av);
	return (0);
}
