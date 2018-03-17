/*
Napisati C program koji računa sumu prvih n
prirodnih brojeva, pri čemu se n zadaje na
početku programa.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, s;

    printf("Uneti broj n: \n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        s += i;
        printf("s = %d\n", s);
    }

    printf("s = %d\n", s);

    return 0;
}
