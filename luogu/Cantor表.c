#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n, i = 1;
    scanf("%d", &n);
    for (i = 1;; i++)
    {
        if (n <= i)
            break;
        n -= i;
    }
    if ((i / 2) * 2 == i)
        printf("%d/%d", n, i + 1 - n);
    else
        printf("%d/%d", i + 1 - n, n);
    system("pause");
    return 0;
}
