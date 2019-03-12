#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int p1, p2, p3;
char s[105];
void exp(int i)
{
    int p, q;
    switch (p3)
    {
    case 1:
        p = 1;
        break;
    case 2:
        p = -1;
        break;
    default:
        break;
    }
    switch (p1)
    {
    case 1:
        q = 0;
        break;
    case 2:
        q = 32;
        break;
    case 3:
        q = -1;
        break;
    default:
        break;
    }
    if (s[i - 1] < 58 && q != -1)
        q = 0;
    for (int j = 1; j < s[i + 1] - s[i - 1]; j++)
        for (int k = 1; k <= p2; k++)
        {
            if(q != -1)
                printf("%c", s[i - p] + p * j - q);
            else
                printf("*");
        }
}
int main()
{
    scanf("%d %d %d", &p1, &p2, &p3);
    getchar();
    scanf("%s", s);
    for (int h = 0; h < strlen(s); h++)
    {
        if (s[h] != '-')
            printf("%c", s[h]);
        else
        {
            int tmp = s[h + 1] - s[h - 1];
            if (s[h - 1] == '-' || s[h + 1] == '-' || s[h + 1] == '\0')
                printf("%c", s[h]);
            else if (tmp > 1 && tmp < 40)
                exp(h);
            else if (tmp < 1 || tmp >= 40)
                printf("%c", s[h]);
            else
                continue;
        }
    }
    system("pause");
    return 0;
}
