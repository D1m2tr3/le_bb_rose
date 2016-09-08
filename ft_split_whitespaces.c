char **ft_split_whitespaces(char *str)
{
    char **dest;
    int len;
    int j;
    int i;
    
    len = wdc(str);
    printf("%d\n", len);
    dest = malloc(sizeof(char**) * (len + 1));
    if (!(len && dest))
         return (NULL);
    dest[len] = 0;
    printf("123\n");
    j = 0;
    i = 0;
    while (dest[j])
    {
        while (str[i] == 9 || str[i] == 10 || str[i] == 32)
            i++;
        len = wds(str, i);
        dest[j] = malloc(sizeof(char*) * (len + 1));
        if (!(dest[j]))
            return (NULL);
        dest[j][len] = 0;
        len = 0;
        while (dest[j][len])
            dest[j][len++] = str[i++];
        j++;
    }
    j = 0;
    while (dest[j])
        printf("%s\n", dest[j++]);
    return (dest);
}
void    main(void)
{
        char str[] = "qwerty qwer  q ";
        ft_split_whitespaces(str);
}
