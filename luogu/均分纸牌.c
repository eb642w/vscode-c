#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[100];
int main()
{
    int n,v=0,p=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        v+=a[i];
    }
    v/=n;
    for(int j=0;j<n;j++)
    {
        a[j]-=v;
    }
    for(int k=0;k<n;k++)
    {
        if(a[k]!=0)
        {
            a[k+1]+=a[k];
            p++;
        }
    }
    printf("%d",p);
    system("pause");
    return 0;
}
