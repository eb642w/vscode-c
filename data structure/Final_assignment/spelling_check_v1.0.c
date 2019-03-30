#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *Dict = fopen("dictionary.txt", "r");
    FILE *article = fopen("article.txt", "r");
    FILE *out = fopen("misspelling.txt", "w");
    fclose(Dict), fclose(article), fclose(out);
    system("pause");
    return 0;
}
