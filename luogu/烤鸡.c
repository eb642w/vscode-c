#include <stdio.h>
#include <stdlib.h>
int a[10][10];
int main()
{
    int n, a, b, c, d, e, f, g, h, i, j, k = 0;
    scanf("%d", &n);
    if (n < 10 || n > 30)
    {
        printf("0");
        system("pause");
        return 0;
    }
    else
    {
        for (a = 1; a <= 3; a++)
        {
            for (b = 1; b <= 3; b++)
            {
                for (c = 1; c <= 3; c++)
                {
                    for (d = 1; d <= 3; d++)
                    {
                        for (e = 1; e <= 3; e++)
                        {
                            for (f = 1; f <= 3; f++)
                            {
                                for (g = 1; g <= 3; g++)
                                {
                                    for (h = 1; h <= 3; h++)
                                    {
                                        for (i = 1; i <= 3; i++)
                                        {
                                            for (j = 1; j <= 3; j++)
                                            {
                                                if (a + b + c + d + e + f + g + h + i + j == n)
                                                {
                                                    k++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", k);
        for (a = 1; a <= 3; a++)
        {
            for (b = 1; b <= 3; b++)
            {
                for (c = 1; c <= 3; c++)
                {
                    for (d = 1; d <= 3; d++)
                    {
                        for (e = 1; e <= 3; e++)
                        {
                            for (f = 1; f <= 3; f++)
                            {
                                for (g = 1; g <= 3; g++)
                                {
                                    for (h = 1; h <= 3; h++)
                                    {
                                        for (i = 1; i <= 3; i++)
                                        {
                                            for (j = 1; j <= 3; j++)
                                            {
                                                if (a + b + c + d + e + f + g + h + i + j == n)
                                                {
                                                    printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}