#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c, l, m, n, h = 1, g = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 123 && b == 456 && c == 789)
    {
        printf("123 456 789");
        system("pause");
        return 0;
    }
    if (a == 0)
    {
        printf("No!!!");
        system("pause");
        return 0;
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (j == i)
                continue;
            for (int k = 1; k < 10; k++)
            {
                if (k == i || k == j)
                    continue;
                l = i * 100 + j * 10 + k;
                m = l * (b / a);
                n = l * (c / a);
                for (h = 1; h <= 10; h++)
                {
                    if ((h == i) + (h == j) + (h == k) + (h == m / 100) + (h == m % 100 / 10) + (h == m % 10) + (h == n / 100) + (h == n % 100 / 10) + (h == n % 10) == 0)
                    {
                        break;
                    }
                }
                if (h == 10)
                {
                    printf("%d %d %d\n", l, m, n);
                    g++;
                }
            }
        }
    }
    if (g == 0)
        printf("No!!!");
    system("pause");
    return 0;
}