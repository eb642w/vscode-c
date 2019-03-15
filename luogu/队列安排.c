#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct line
{
    int id;
    int p;
    struct line *front,*next;
} line;
line student[100001];
int main()
{
    line *head=student[1].front;
    head->next=&student[1];
    student[1].front=&student[1];
    student[1].next=&student[1];
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        student[i].id=i;
        student[i].p=1;
    }
    for(int i=2;i<=n;i++)
    {
        int num,lr;
        scanf("%d %d",&num,&lr);
        if(lr==0)
        {
            student[i].front=student[num].front;
            student[num].front->next=&student[i];
            student[i].next=&student[num];
            student[num].front=&student[i];
        }
        else
        {
            student[i].front=&student[num];
            student[i].next=student[num].next;
            student[]
            student[num].next=&student[i];
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int y;
        scanf("%d",&y);
        student[y].p=0;
    }
    int b=head->id;
    do
    {
        if(head->p==1)
            printf("%d ",head->id);
        head=head->next;
    }while(b!=head->id);
    system("pause");
    return 0;
}
