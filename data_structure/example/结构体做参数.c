# include <stdio.h>
# include <stdlib.h>

//创建一个Student结构 
struct Student
{
    char name[30];
    float fScore[3];
}student={"dire",98.5,89.0,93.5}; //初始化结构体变量 

void Display(struct Student su) //形参为同类型的结构体(Student结构) 
{
    printf("-----Information------\n");
    printf("Name:%s",su.name);
    printf("Chinese:%.2f\n",su.fScore[0]);
    printf("Math:%.2f\n",su.fScore[1]);
    printf("English:%.2f",su.fScore[2]);
    printf("平均分数为:%.2f\n",(su.fScore[0]+su.fScore[1],su.fScore[2])/3);
}

int main ()
{
    
    Display(student);
    system("pause");
    return 0;
 }