#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[110];
int cmp(const void *a,const void *b)
{
    return(*(int *)a-*(int *)b);
}
int main()
{
    int n,p=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    qsort(a,n+1,sizeof(a[0]),cmp);
    for(int j=1;j<=n;j++)
    {
        if(a[j]==a[j-1])
            continue;
        p++;
    }
    printf("%d\n",p);
    for(int k=1;k<=n;k++)
    {
        if(a[k]==a[k-1])
            continue;
        printf("%d ",a[k]);
    }
    system("pause");
    return 0;
}
