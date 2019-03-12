#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(x,y) x^=y^=x^=y
int a[300][5],b[300][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        a[i][3]=i+1;
        a[i][4]=a[i][0]+a[i][1]+a[i][2];
    }
    for(int j=0;j<n-1;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(a[j][4]<a[k][4])
            {
                swap(a[j][4],a[k][4]);
                swap(a[j][3],a[k][3]);
                swap(a[j][2],a[k][2]);
                swap(a[j][1],a[k][1]);
                swap(a[j][0],a[k][0]);
            }
            else if(a[j][4]==a[k][4])
            {
                if(a[j][0]<a[k][0])
                {
                    swap(a[j][4],a[k][4]);
                    swap(a[j][3],a[k][3]);
                    swap(a[j][2],a[k][2]);
                    swap(a[j][1],a[k][1]);
                    swap(a[j][0],a[k][0]);
                }
                else if(a[j][0]==a[k][0])
                {
                    if(a[j][3]>a[k][3])
                    {
                        swap(a[j][4],a[k][4]);
                        swap(a[j][3],a[k][3]);
                        swap(a[j][2],a[k][2]);
                        swap(a[j][1],a[k][1]);
                        swap(a[j][0],a[k][0]);
                    }
                }
            }
        }
    }
    for(int h=0;h<5;h++)
        printf("%d %d\n",a[h][3],a[h][4]);
    system("pause");
    return 0;
}
