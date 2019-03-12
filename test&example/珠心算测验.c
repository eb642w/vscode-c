#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[100], b[100];
int cmp(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}
int main()
{
    int n, q = 0, I = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), cmp);
    for (int j = 0; j < n - 1; j++)
    {
        if (a[j] + a[j + 1] > a[n - 1])
            break;
        for (int k = j + 1; k < n; k++)
        {
            if (a[j] + a[k] > a[n - 1])
                break;
            else
            {
                for (int h = n - 1; h >= 0; h--)
                {
                    if (a[h] < a[j] + a[k])
                        break;
                    else if (a[h] == a[j] + a[k])
                    {
                        b[q] = a[h];
                        q++;
                    }
                }
            }
        }
    }
    qsort(b, q, sizeof(b[0]), cmp);
    for (int v = 0; v < q - 1; v++)
        for (int w = v + 1; w < q; w++)
        {
            if (b[v] < b[w])
                break;
            else if (b[v] == b[w] && b[w] != -1)
            {
                I++;
                b[w] = -1;
            }
        }
    printf("%d", q - I);
    system("pause");
    return 0;
}
