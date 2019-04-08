#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void reverse(char *s)
{
    int temp, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
int main()
{
    // char *p;
    // FILE *a=fopen("article.txt","rb+");
    // FILE *b=fopen("test.txt","wb+");
    // fseek(a,0,SEEK_END);
    // int length=ftell(a);
    // rewind(a);
    // p=(char *)malloc(sizeof(char)*(length+1));
    // fread(p,sizeof(char),length,a);
    // int j=0;
    // for(int i=0;i<length;i++)
    // {
    //     fprintf(b,"i : %d | %d : %c\n",i,j,p[i]);
    //     if(p[i]!='\r')
    //         j++;
    // }
    char num[20];
    int i = 0;
    int c = 1234560;
    while (c != 0)
    {
        num[i]=c%10+'0';
        c/=10;
        i++;
    }
    num[i]='\0';
    reverse(num);
    printf("%s",num);
    system("pause");
    return 0;
}
