#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(x,y) x^=y^=x^=y
int d[50][3];
int main()
{
    int a,m,n,p,k=1,sum=0,path_x=0,i=1,j=1;
    scanf("%d%d%d",&m,&n,&p);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a);
            if(a>0)
            {
                d[k][0]=i;
                d[k][1]=j;
                d[k][2]=a;
                k++;
            }
        }
        
    /*for(int h=1;h<k-1;h++)
        for(int f=h+1;f<k;f++)
        {
            if(d[h][2]<d[f][2])
            {
                swap(d[h][0],d[f][0]);
                swap(d[h][1],d[f][1]);
                swap(d[h][2],d[f][2]);
            }
        }
    d[0][1]=d[1][1];
    for(int e=1;e<k;e++)
    {
        int path_1=abs(d[e][0]-d[e-1][0])+abs(d[e][1]-d[e-1][1])+1;
        if(path_x+path_1+d[e][0]>p)
            break;
        else
        {
            sum+=d[e][2];
            path_x+=path_1;
        }
    }*/
    printf("%d",sum);
    system("pause");
    return 0;
}
