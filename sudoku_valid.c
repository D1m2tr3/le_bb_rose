#define	Y(x) ((x) / 3 + (b / 3) * 3) + 1
#define X(x) (x) % 3 + (b % 3) * 3
#define ISNUM(x) (x) >= '0' && (x) <= '9'
#define ALLOWED(x) (x) == '.' || ISNUM(x)


int valid_line(char **tab, int l)
{
	int i;
	int j;
	
	i = 0;
	if (!(ALLOWED(tab[l][i])))
		return (1);
	while (tab[l][i + 1])
	{
		j = i + 1
		while (tab[l][j])
		{
			if (!(ALLOWED(tab[l][j])) || tab[l][i] == tab[l][j]
				&& ISNUM(tab[l][i]) && ISNUM(tab[l][j]))
				return (1);
			j++;
		}
		if (j != 9)
			return (1);
		i++;
	}
	return(l == 9 ? 0 : valid_line(tab, l + 1));
}

int	valid_column(char **tab, int c)
{
	int i;
	int j;
	
	i = 1;
	while (tab[i + 1][c])
	{
		j = i + 1
		while (tab[j][c])
		{
			if (tab[i][c] == tab[j][c] && ISNUM(tab[i][c]) && ISNUM(tab[j][c]))
				return (1);
			j++;
		}
		i++;
	}
	return(c == 8 ? 0 : valid_line(tab, c + 1));
}

int	valid_block(char **tab, int b)
{
	int i;
	int j;

	i = 0;
	while (i + 1 < 9)
	{
		j = i + 1
		while (j < 9)
		{
			if (tab[Y(i)][X(i)]] == tab[Y(j)][X(j)] && ISNUM(tab[Y(i)][X(i)]])
				&& ISNUM(tab[Y(j)][X(j)))
				return (1);
			j++;
		}
		i++;
	}
	return (b == 8 ? 0 : valid_block(tab, b + 1));
}
