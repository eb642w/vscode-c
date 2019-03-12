#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct PLR
{
    int id;
    int score;
    int power;
} PLR;
int cmp(const void *p1, const void *p2)
{
    PLR *a = (PLR *)p1;
    PLR *b = (PLR *)p2;
    if (a->score != b->score)
        return b->score - a->score;
    return a->id - b->id;
}
PLR plr[20000], win[10000], lose[10000], tmp[20000];
void merge(PLR *a, int a_l, PLR *b, int b_l)
{
    int i = 0, j = 0, k = 0;
    while (i <= a_l && j <= b_l)
    {
        if (a[i].score > b[j].score)
            tmp[k++] = a[i++];
        else if (a[i].score == b[j].score)
        {
            if (a[i].id < b[j].id)
                tmp[k++] = a[i++];
            else
                tmp[k++] = b[j++];
        }
        else
            tmp[k++] = b[j++];
    }
    while (i <= a_l)
        tmp[k++] = a[i++];
    while (j <= b_l)
        tmp[k++] = b[j++];
    for (int h = 0; h < k; h++)
        plr[h] = tmp[h];
}
int main()
{
    int n, r, q;
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 0; i < 4 * n; i++)
    {
        if (i < 2 * n)
        {
            scanf("%d", &plr[i].score);
            plr[i].id = i + 1;
        }
        else
            scanf("%d", &plr[i - 2 * n].power);
    }
    qsort(plr, 2 * n, sizeof(PLR), cmp);
    for (int j = 0; j < r; j++)
    {
        for (int k = 0; k < n; k++)
        {
            int m;
            if (plr[2 * k].power > plr[2 * k + 1].power)
            {
                plr[2 * k].score++;
                win[k] = plr[2 * k];
                lose[k] = plr[2 * k + 1];
            }
            else
            {
                plr[2 * k + 1].score++;
                win[k] = plr[2 * k + 1];
                lose[k] = plr[2 * k];
            }
        }
        merge(win, n - 1, lose, n - 1);
    }
    printf("%d", plr[q - 1].id);
    system("pause");
    return 0;
}
