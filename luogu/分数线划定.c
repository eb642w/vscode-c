#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(x,y) x^=y^=x^=y;
int a[5000][2];
int main()
{
    int n, m, h = 0, b = 0;
    scanf("%d%d", &n, &m);
    m *= 1.5;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i][0], &a[i][1]);
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (a[j][1] < a[k][1])
            {
                swap(a[j][1],a[k][1]);
                swap(a[j][0],a[k][0]);
            }
            else if(a[j][1]==a[k][1] && a[j][0]>a[k][0])
                swap(a[j][0],a[k][0]);
        }
    }
    for (h = 0; h < n; h++)
    {
        if (h + 1 == m)
            b = a[h][1];
        if (a[h][1] < b)
            break;
    }
    printf("%d %d\n", b, h);
    for (int v = 0; v < h; v++)
        printf("%d %d\n", a[v][0], a[v][1]);
    system("pause");
    return 0;
}
