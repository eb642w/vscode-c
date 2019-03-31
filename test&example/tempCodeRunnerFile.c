#include "stdio.h"

#include "math.h"

int main()

{

    int a,b,c;

    c=0,b=0;

    scanf("%d",&a);

    for (c=0;a!=0;b++)

	{c=c*10+a%10;
    

	a/=10;
    if(c==0)
        printf("0");
	}

    printf("%d",c);
    system("pause");
    return 0;
}
