#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define maxnum 10000

int length;
FILE *Dict, *article, *out;
typedef struct Trie_node
{
    int sign;
    struct Trie_node *next[28];
}trie;

void File_open()
{
    Dict = fopen("dictionary.txt", "rb");
    article = fopen("article.txt", "rb");
    out = fopen("misspelling.txt", "wb");
}
void File_close()
{
    fclose(Dict);
    fclose(article);
    fclose(out);
}
void insert()
{}
void Read(FILE *file_in)
{
    char *temp_head,*temp_body;
    int temp_length;
    fseek(file_in, 0, SEEK_END);
    length = ftell(file_in);
    temp_length=length;
    rewind(file_in);
    temp_head=temp_body;
    temp_body=(char *)malloc(sizeof(char)*(maxnum+1));
    while(temp_length>maxnum)
    {
        int tmp_length=maxnum-strlen(temp_head)+1;
        temp_body=(char *)malloc(sizeof(char)*tmp_length);
        fread(temp_body,sizeof(char),tmp_length,Dict);
        temp_body[maxnum]

    }
}

int main()
{
    File_open();
    Read(Dict);
    File_close();
    system("pause");
    return 0;
}
