#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[15];
int main()
{
    int i = 0, j, tmp, k = 0;
    scanf("%s", a);
    for (i = 0;; i++)
    {
        if (a[i] == '\0')
        {
            i--;
            break;
        }
    }
    j = i;
    for (i = 0; i <= j / 2; i++)
    {
        tmp = a[i];
        a[i] = a[j - i];
        a[j - i] = tmp;
    }
    while (a[k] != '\0')
    {
        if (a[k] != '0')
            break;
        k++;
    }
    if (a[j] == '-')
    {
        printf("-");
        if (k == j)
        {
            printf("0");
            system("pause");
            return 0;
        }
        for (; k < j; k++)
        {
            printf("%c", a[k]);
        }
    }
    else if (a[j] != '-' && k == j + 1)
    {
        printf("0");
        system("pause");
        return 0;
    }
    else
    {
        for (; k <= j; k++)
        {
            printf("%c", a[k]);
        }
    }
    system("pause");
    return 0;
}
