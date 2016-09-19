#include "./header.h"

int		line(char **tab, int l)
{
	int i;
	int j;
	
	i = 0;
	while (tab[l][i + 1])
	{
		j = i + 1;
		while (tab[l][j])
		{
			if (ISNUM(tab[l][i]) && ISNUM(tab[l][j]) && tab[l][i] == tab[l][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		column(char **tab, int c)
{
	int i;
	int j;
	
	i = 1;
	while (tab[i + 1][c])
	{
		j = i + 1;
		while (tab[j][c])
		{
			if (ISNUM(tab[i][c]) && ISNUM(tab[j][c]) && tab[i][c] == tab[j][c])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		block(char **tab, int b)
{
	int i;
	int j;

	i = 0;
	while (i + 1 < 9)
	{
		j = i + 1;
		while (j < 9)
		{
			if (tab[YB(i)][XB(i)] == tab[YB(j)][XB(j)] && ISNUM(tab[YB(i)][XB(i)])
				&& ISNUM(tab[YB(j)][XB(j)]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		writer(char **tab, int a, int i)
{
	if (i > 9)
	{
		tab[Y(a)][X(a)] = '.';
		return (1);
	}
	tab[Y(a)][X(a)] = i + 48;
	if (line(tab, Y(a)) || column(tab, X(a)) || block(tab, B(a)))
	{
		writer(tab, a, i + 1);
	}
	return (0);
}

int 	resolve(char **tab, int a, int fin)
{
	int f;

	f = 0;
	if (fin == 9 * 9)
		return (1);
	if (a == 9 * 9)
		return(resolve(tab, 0));
	if (tab[Y(a)][X(a)] == '.')
	{
		if (writer(tab, a, 1))
			return;
	}
	resolve(tab, a + 1)
}

