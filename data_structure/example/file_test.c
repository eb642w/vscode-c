#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct test
{
    char name[10];
    int num;
}y,p={"py",66};
int main()
{
    FILE *fp=fopen("test.txt","w+");
    if(fp==0)
        puts("error");
    for(int i=0;i<3;i++)
    {
        fwrite(&p,sizeof(p),1,fp);
        rewind(fp);
        fread(&y,sizeof(p),1,fp);
        printf("%s %d",y.name,y.num);
    }
    fclose(fp);
    system("pause");
    return 0;
}/* 
233 */