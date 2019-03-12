#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(x,y) x^=y^=x^=y

int g[100000];

int cmp(const void *x,const void *y)
{
    return (*(int *)y-*(int *)x); 
}

int main()
{
    int n,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&g[i]);
    qsort(g,n,sizeof(g[0]),cmp);
    for(int j=n-1;j>=1;j--)
    {
        if(g[j]>g[j-1])
            for(int k=j-1;g[k]>=g[k+1];k--)
                swap(g[k],g[k+1]);
        s+=g[j]+g[j-1];
        g[j-1]+=g[j];
        g[j]=0;
    }
    printf("%d",s);
    system("pause");
    return 0;
}
