#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[100][25], b[100][3];
int c[100][3];
int main()
{
    int n, p, money = 0, sum = 0, max = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %c %c %d", a[i], &c[i][0], &c[i][1], &b[i][0], &b[i][1], &c[i][2]);
        if (c[i][0] > 80 && c[i][2] >= 1)
            money += 8000;
        if (c[i][0] > 85 && c[i][1] > 80)
            money += 4000;
        if (c[i][0] > 90)
            money += 2000;
        if (c[i][0] > 85 && b[i][1] == 'Y')
            money += 1000;
        if (c[i][1] > 80 && b[i][0] == 'Y')
            money += 850;
        sum += money;
        if (money > max)
        {
            max = money;
            p = i;
        }
        money=0;
    }
    printf("%s\n%d\n%d\n", a[p], max, sum);
    system("pause");
    return 0;
}
