#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    char name[10];
    int age;
}example[2]={{"py",19},{"zst",18}};

void swap_struct(struct node *a,struct node *b)
{
    struct node tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int main()
{
    int i;
    for(i=0;i<2;i++)
        printf("%s %d\n",example[i].name,example[i].age);
    swap_struct(&example[0],&example[1]);
    for(i=0;i<2;i++)
        printf("%s %d\n",example[i].name,example[i].age);
    system("pause");
    return 0;
}
