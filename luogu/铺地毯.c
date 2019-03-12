#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int v[4][10000];
int main()
{
    int n, o, p, i = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &v[0][i], &v[1][i], &v[2][i], &v[3][i]);
    }
    i--;
    getchar();
    scanf("%d %d", &o, &p);
    for (; i >= 0; i--)
    {
        if (o >= v[0][i] && o <= v[0][i] + v[2][i] && p >= v[1][i] && p <= v[1][i] + v[3][i] && i >= 1)
        {
            printf("%d", i);
            break;
        }
    }
    if (i == -1)
        printf("-1");
    system("pause");
    return 0;
}
