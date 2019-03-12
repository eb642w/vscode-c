#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char num_str[20][100],tmp[100];

int c_cmp(char a,char b)
{
    return (int)a-(int)b;
}

void str_swap(char *c,char *d)
{
    char *tmp;
    strcpy(tmp,c);
    strcpy(c,d);
    strcpy(d,tmp);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",num_str[i]);
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            int k=0;
            while(num_str[i][k]!='\0' && num_str[j][k]!='\0')
            {
                if(c_cmp(num_str[i][k],num_str[j][k])<0)
                {
                    str_swap(num_str[i],num_str[j]);
                    break;
                }
                else if(c_cmp(num_str[i][k],num_str[j][k])==0)
                    k++;
                else
                    break;
                
            }
            if(num_str[i][k]=='\0' && num_str[j][k]!='\0' && c_cmp(num_str[i][0],num_str[j][k])<0)
        }
    system("pause");
    return 0;
}
