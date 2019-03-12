#include <stdio.h>
#include <stdlib.h>
int v[2][5000];
int main()
{
    int n, s, a, b, p = 0, tmp1, tmp2;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &v[0][i], &v[1][i]);
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (v[1][j] > v[1][k])
            {
                tmp1 = v[0][j];
                v[0][j] = v[0][k];
                v[0][k] = tmp1;
                tmp2 = v[1][j];
                v[1][j] = v[1][k];
                v[1][k] = tmp2;
            }
        }
    }
    for (int h = 0; h < n; h++)
    {
        if (v[0][h] <= a + b && s >= v[1][h])
        {
            p++;
            s -= v[1][h];
        }
    }
    printf("%d", p);
    system("pause");
    return 0;
}
