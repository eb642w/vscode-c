#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int a[100000];

int cmp(const void *a, const void *b)
{
    return (*(int *)a-*(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), cmp);
    for (int j = 0; j < n; j++)
        printf("%d ", a[j]);
    system("pause");
    return 0;
}
