#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=sqrt(n);i++)
        printf("%d ",i*i);
    system("pause");
    return 0;
}
