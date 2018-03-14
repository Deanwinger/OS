#include <stdio.h>

main()
{
    int n = 123;
    int s = -1234;
    printd(n);
    printd(s);
}

void printd(int n)
{
    if (n < 0){
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n%10 + '0');

}