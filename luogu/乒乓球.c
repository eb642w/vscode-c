#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int b[10000][2], c[10000][2];
int main()
{
    char a;
    int i = 0, j = 0, k = 0;
    for (i = 0;; i++)
    {
        scanf("%c", &a);
        if (a == 'E')
            break;
        else
        {
            if ((b[j][0] >= 11 || b[j][1] >= 11) && (b[j][0] - b[j][1] >= 2 || b[j][0] - b[j][1] <= -2))
                j++;
            if ((c[k][0] >= 21 || c[k][1] >= 21) && (c[k][0] - c[k][1] >= 2 || c[k][0] - c[k][1] <= -2))
                k++;
            if (a == 'W')
            {
                b[j][0]++;
                c[k][0]++;
            }
            else if (a == 'L')
            {
                b[j][1]++;
                c[k][1]++;
            }
        }
    }
    if ((b[j][0] >= 11 || b[j][1] >= 11) && (b[j][0] - b[j][1] >= 2 || b[j][0] - b[j][1] <= -2))
        j++;
    if ((c[k][0] >= 21 || c[k][1] >= 21) && (c[k][0] - c[k][1] >= 2 || c[k][0] - c[k][1] <= -2))
        k++;
    for (int h = 0; h <= j; h++)
        printf("%d:%d\n", b[h][0], b[h][1]);
    printf("\n");
    for (int v = 0; v <= k; v++)
        printf("%d:%d\n", c[v][0], c[v][1]);
    system("pause");
    return 0;
}
