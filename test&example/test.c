#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int cost, weight, distance;
    scanf("%d,%d", &weight, &distance);
    printf("%d,%d",weight,distance);
    if (weight <= 15)
        printf("5");
    else if (weight <= 30)
        printf("9");
    else if (weight <= 45)
        printf("12");
    else if (weight <= 60)
        printf("%d", 14 + distance / 1000);
    else
        printf("%d", 15 + 2 * distance / 1000);
    system("pause");
    return 0;
}
