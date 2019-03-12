#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char a[20][105],y[105];
int main()
{
    int m,n,p=0,k,i=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        m=strlen(a[i]);
        if(m>p)
        {
            p=m;
            strcpy(y,a[i]);
            k=i+1;
        }
        else if(m==p)
        {
            for(int j=0;a[i][j]!='\0';j++)
            {
                if(a[i][j]-'0'<y[j]-'0')
                    break;
                else if(a[i][j]-'0'>y[j]-'0')
                {
                    strcpy(y,a[i]);
                    k=i+1;
                    break;
                }
            }
        }
    }
    printf("%d\n%s",k,y);
    system("pause");
    return 0;
}
