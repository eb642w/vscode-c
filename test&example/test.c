#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char in[1000000];
int main()
{
    char *p;
    FILE *d=fopen("dictionary.txt","rb+");
    FILE *a=fopen("article.txt","rb+");
    fread(in,sizeof(char),1000000,a);
    if(strstr(in,"\r\n")!=NULL)
        printf("%s",p);
    else
        printf("judge");
    system("pause");
    return 0;
}
