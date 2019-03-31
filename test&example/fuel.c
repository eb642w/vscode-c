#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void error()
{
    printf("error");
}
int main()
{
    double a, price, discount;
    int b;
    char c;
    scanf("%lf,%d,%c", &a, &b, &c);
    if (a < 0 || (c != 'm' && c != 'e'))
    {
        error();
        system("pause");
        return 0;
    }
    switch (b)
    {
    case (90):
    {
        price = 6.95;
        break;
    }
    case (93):
    {
        price = 7.44;
        break;
    }
    case (97):
    {
        price = 7.93;
        break;
    }
    default:
    {
        error();
        system("pause");
        return 0;
    }
    }
    discount = (c == 'm') ? 0.05 : 0.03;
    printf("%.2lf", a * price * discount);
    system("pause");
    return 0;
}
