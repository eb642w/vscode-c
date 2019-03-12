#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
   double s,x,p=0.0,y=7.0;
   scanf("%lf%lf",&s,&x);
   while(1){
        if(p>=s-x)
        {
            if(p+y<=s+x)
            {
                printf("y"); 
            }
            else
            {
                printf("n"); 
            }
            system("pause");
            return 0;
        }
        p+=y; 
        y*=0.98;
   }
}

