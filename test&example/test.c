#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n=1;
    printf("%d\n",n);
    fwrite(&n,sizeof(int),1,stdout);
    system("pause");
    return 0;
}
