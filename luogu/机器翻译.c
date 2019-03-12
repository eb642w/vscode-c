#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[105],b[1000];
int main()
{
    int m,n,p=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]==0) b[i]=-1;
        int j=0;
        for(j=0;j<=i && j<=m;j++)
        {
            if(a[j]==b[i]) break;
        }
        if(j==i+1 || j==m+1)
        {
            p++;
            if(p<=m)
            {
                a[p-1]=b[i];
            }
            else
            {
                for(int k=0;k<m;k++)
                {
                    a[k]=a[k+1];
                    if(k==m-1) a[k]=b[i];
                }
            }
            
        }
    }
    printf("%d",p);
    system("pause");
    return 0;
}


