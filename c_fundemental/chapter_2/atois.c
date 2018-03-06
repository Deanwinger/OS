#include <stdio.h>

// int atois( char s[])
// {
//     int i, n;
//     n = 0;
//     for ( i = 0; s[i] >= '0' && s[i] <= '9'; ++i )
//     {
//         n = n * 10 + (s[i] - '0');
//         printf("%d current value is: %d\n", i+1, n);
//     }
//     return n;
// }

// main()
// {
//     int n;
//     char s[13] = "123";
//     n = atois(s);
//     printf("The answer is: %d", n);
// }

main()
{
    char s[5] = "abcde";
    char t[5] = "ABCDE";
    fortest(s);
    fortest(t);
    return;
}

void fortest( char * s)
{
    int i=0;
    int n;

    for (i = 0; i < 5; ++i){
        n = s[i] - '0';
        printf("what you are looking for is: %d\n", n);
    }
    return ;

}