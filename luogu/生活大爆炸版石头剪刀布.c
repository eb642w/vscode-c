#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int j[5][5] = {{0, -1, 1, 1, -1},
               {1, 0, -1, 1, -1},
               {-1, 1, 0, -1, 1},
               {-1, -1, 1, 0, 1},
               {1, 1, -1, -1, 0}};
int ai[200], bi[200];
int main()
{
    int n, a, b, aj = 0, bj = 0, A = 0, B = 0;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < a; i++)
        scanf("%d", &ai[i]);
    for (int j = 0; j < b; j++)
        scanf("%d", &bi[j]);
    for (int k = 1; k <= n; k++)
    {
        int m = j[ai[aj]][bi[bj]];
        if (m == 1)
            A++;
        else if (m == -1)
            B++;
        aj++;
        bj++;
        if (k % a == 0)
            aj = 0;
        if (k % b == 0)
            bj = 0;
    }
    printf("%d %d", A, B);
    system("pause");
    return 0;
}
