#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int next[100];
char str_1[] = "abcabababca", str_2[] = "ababca";

int kmp(char *a, char *b)
{
    int i = 0, j = 0;
    while (i < strlen(a) && j < strlen(b))
    {
        if (j == -1 || a[i] == b[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j == strlen(b))
        return i - j;
    else
        return -1;
}

void get_next(char *a, int *b)
{
    b[0] = -1;
    int i = 0, j = -1;
    while (i < strlen(a))
    {
        if (j == -1 || a[i] == a[j])
        {
            ++i;
            ++j;
            b[i] = j;
        }
        else
            j = b[j];
    }
}
int main()
{
    get_next(str_2, next);
    int n = kmp(str_1, str_2);
    printf("%d", n);
    system("pause");
    return 0;
}
