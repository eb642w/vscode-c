#include <stdlib.h>
#include <stdio.h>
typedef struct Friend
{
    int w;
    int num;
} Friend; //这样的话，后面才能找到这个新声明的类型
int Comp(const void *p1, const void *p2)
{
    Friend *a = (Friend *)p1;
    Friend *b = (Friend *)p2;
    if (a->w != b->w)
        return b->w - a->w;
    return a->num - b->num;
}
Friend FRIEND[20010]; //数组一般需要大小固定
int e[11];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n+10; i++)
    {
        if (i < 10)
            scanf("%d", &e[i]);
        else
        {
            scanf("%d", &FRIEND[i - 10].w);
            FRIEND[i - 10].num = i - 9;
        }
    }
    qsort(FRIEND, n, sizeof(Friend), Comp);
    for (int j = 0; j < n; j++)
        FRIEND[j].w += e[j % 10];
    qsort(FRIEND, n, sizeof(Friend), Comp);
    for (int h = 0; h < k; h++)
        printf("%d ", FRIEND[h].num);
    system("pause");
    return 0;
}