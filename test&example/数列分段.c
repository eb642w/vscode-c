#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[100000];
int main()
{
    int n, m, s = 0, h = 1;
    scanf("%d%d", &n, &m);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        if (s + a <= m)
        {
            s += a;
        }
        else
        {
            h++;
            s = a;
        }
    }
    printf("%d", h);
    system("pause");
    return 0;
}
