#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int prm(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int prm_thr(int a, int b, int c)
{
    if (prm(a) + prm(b) + prm(c) == 3)
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n - 4; i++)
    {
        for (int j = 2; j <= n - 4; j++)
        {
            int k = n - i - j;
            if (prm_thr(i, j, k) == 1)
            {
                printf("%d %d %d\n", i, j, k);
                system("pause");
                return 0;
            }
        }
    }
}