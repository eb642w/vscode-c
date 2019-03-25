#include <stdio.h>
#include<stdlib.h>
#include <string.h>
void form(char key1[], char a[])
{
    int i = 0, l, j, k, s = 1;
    l = strlen(key1);
    for (i = 0; i < l; i++)
        a[i] = key1[i];
    for (i = 0, k = 25; i < 26; i++)
    {
        for (j = 0; j < l; j++)
            if (('a' + i) == key1[j])
                s = 0;
        if (s)
            a[k--] = 'a' + i;
    }
    a[26] = 0;
}
void cut(char key[], char key1[])
{
    int i, j, k, l, x;
    l = strlen(key);
    for (i = 0, k = 0; i < l; i++)
    {
        x = 0;
        for (j = 0; j < i; j++)
            if (key[j] != key[i])
                x = 1;
        if (x)
            key1[k++] = key[i];
    }
    key[k] = 0;
}

char change(char c, char a[])

{
    int i;
    i = c - 'a';
    c = a[i];
    return c;
}
int main()
{
    int i, c;
    char key[111], a[36], key1[36];
    FILE *in, *out;
    in = fopen("encrypt.txt", "r");
    out = fopen("output.txt", "w");
    gets(key);
    puts(key);
    cut(key, key1);
    form(key1, a);
    while ((c = fgetc(in) != EOF))
    {
        char ab=change(c, a);
        fputc(c, out);
    }
    system("pause");
    fclose(in);
    fclose(out);
}