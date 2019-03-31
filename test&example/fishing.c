#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int day,count=0;
    scanf("%d",&day);
    while(count<=day)
    {
        count+=5;
    }
    day-=count-5;
    if(day<=3)
        printf("Fishing");
    else
        printf("Drying");
    system("pause");
    return 0;
}
