#include <stdio.h>
#include <stdlib.h>

int     wdc(char *str) // fonctionne
{
    int i;
    int wdc;
    
    i = 0;
    wdc = 0;
    while (str[i])
    {
        while (str[i] == 9 || str[i] == 10 || str[i] == 32)
            i++;
        if (!(str[i] == 9 || str[i] == 10 || str[i] == 32 || str[i] == 0))
            wdc++;
        while (!(str[i] == 9 || str[i] == 10 || str[i] == 32 || str[i] == 0))
            i++;
    }
    return (wdc);
}

int     wds(char *str, int *ptr)
{
    int i;
    
    while (str[*ptr] == 9 || str[*ptr] == 10 || str[*ptr] == 32)
        (*ptr)++;
    if (!(str[*ptr] == 9 || str[*ptr] == 10 || str[*ptr] == 32 || str[*ptr] == 0))
        i = *ptr;
    while (!(str[i] == 9 || str[i] == 10 || str[i] == 32 || str[i] == 0))
        i++;
   return (i - *ptr);    
}

int    allocator(char **str, int len)
{
    *str = malloc(sizeof(char*) * (len + 1));
    if (!(*str))
        return (1);
    str[len] = 0;
    return (0);
}

char **ft_split_whitespaces(char *str)
{
    char **dest;
    int len_tab;
    int len_wd;
    int j;
    int i;
    int k;
    
    len_tab = wdc(str);
    dest = malloc(sizeof(char**) * (len_tab + 1));
    if (!(len_tab && dest))
         return (NULL);
    dest[len_tab] = 0;
    j = 0;
    i = 0;
    while (j < len_tab)
    {
        len_wd = wds(str, &i);
        dest[j] = malloc(sizeof(char*) * (len_wd + 1));
        if (!(dest[j]))
            return (NULL);
        dest[j][len_wd] = 0;
        k = 0;
        while (k < len_wd)
            dest[j][k++] = str[i++];
        j++;
    }
    return (dest);
}

void    main(void)
{
        char str[] = "     qwerty qw\ner  q bwabwa ";
        ft_split_whitespaces(str);
}
