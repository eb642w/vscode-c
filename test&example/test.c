#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char *p;
    FILE *a=fopen("article.txt","rb+");
    FILE *b=fopen("test.txt","wb+");
    fseek(a,0,SEEK_END);
    int length=ftell(a);
    rewind(a);
    p=(char *)malloc(sizeof(char)*(length+1));
    fread(p,sizeof(char),length,a);
    int j=0;
    for(int i=0;i<length;i++)
    {
        fprintf(b,"i : %d | %d : %c\n",i,j,p[i]);
        if(p[i]!='\r')
            j++;
    }
    system("pause");
    return 0;
}
