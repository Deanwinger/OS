#include <stdio.h>

int main()
{
    int n, i = 0;
    char s[6] = "aABcDe";
    for ( i=0; i < 6; ++i )
    {
        n = lowers(s[i]);
        printf("used to be %d, now is %d\n", s[i], n);
    }
    // {
    //     printf("used to be %c, behind integer is %d\n", s[i], s[i]);
    // }
        

}

/* lower: convert c to lower case; ASCII only */
int lowers( int c )
{
    if ( c >= 'A' && c <= 'Z' )
        return c + 'a' - 'A';
    else
        return c;
}
