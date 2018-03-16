

void main()
{
    return ;
}

void strcpys(char *s, char *t)
{
    int i;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpyp(char *s, char *t)
{
    while ((*s = *t) != '\0')
        t++;
        s++;
}

void strcpypp(char *s, char *t)
{
    while((*s++ = *t++) != '\0')
        ;
}

void strcpypf(char *s, char *t)
{
    while (*s = *t)
        ;
}