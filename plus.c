#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num_a[105],num_b[105];

void reverse(char s[])
{
    int temp, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void swap(char str_1[], char str_2[])
{
    char tmp[105];
    strcpy(tmp, str_1);
    strcpy(str_1, str_2);
    strcpy(str_2, tmp);
}

void CmpThenSwap(char str_3[], char str_4[])
{
    int v;
    if (strlen(str_3) > strlen(str_4))
    {
        swap(str_3, str_4);
    }
}

void up(char *s)
{
    if(*s+1>'9')
    {
        *s='0';
        up(s+1);
    }
    else
    {
        *s+=1;
    }
    
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %s",num_a,num_b);
        reverse(num_a);
        reverse(num_b);
        num_a[strlen(num_a)]='0';
        num_b[strlen(num_b)]='0';
        CmpThenSwap(num_a,num_b);
        for(int i=0;i<strlen(num_b);i++)
        {
            int tmp;
            if(i<strlen(num_a))
            {
                tmp=num_a[i]+num_b[i]-'0'-'0';
                if(tmp<10)
                {
                    num_b[i]='0'+tmp;
                    continue;
                }
                else
                {
                    num_b[i]='0'+tmp-10;
                    up(&num_b[i+1]);
                    continue;
                }
            }
            else
            {
                num_b[i]=num_b[i];
            }
        }
        reverse(num_b);
        int i;
        for(i=0;i<strlen(num_b)-1 && num_b[i]=='0';i++){}
        puts(&num_b[i]);
    }
    system("pause");
    return 0;
}
