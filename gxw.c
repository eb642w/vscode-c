#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char sentense[70], word[80];
int last, first, pos, sum_pos, num, remain1 = 0, remain2 = 0, wrong_num;
long t1, t2;
typedef struct A
{
	int end;
	struct A *next[26];
} * link, tree;
link start, p, q;
typedef struct B
{
	char word[80];
	int times, *place;
	struct B *next, *last;
} * link_2, tree_2;
link_2 start_2, end_2, p_2, q_2;
void change(char m[]) //大写转小写
{
	int i;
	for (i = 0; i < strlen(m); i++)
		if ('A' <= m[i] && m[i] <= 'Z')
			m[i] += 'a' - 'A';
	return;
}
void begin() //初始化
{
	int i;
	start = (link)malloc(sizeof(tree));
	for (i = 0; i < 26; i++)
		start->next[i] = NULL;
	start->end = 0;
	start_2 = (link_2)malloc(sizeof(tree_2));
	end_2 = (link_2)malloc(sizeof(tree_2));
	start_2->next = end_2;
	start_2->last = NULL;
	end_2->last = start_2;
	end_2->next = NULL;
	start_2->times = 999;
	strcpy(start_2->word, "!\0");
	end_2->times = 0;
	strcpy(end_2->word, "zzzzzzzzzzzzz\0");
	return;
}
void in(char m[]) //输入字典单词
{
	int i, j;
	p = start;
	for (i = 0; i < strlen(m); i++)
	{
		if (p->next[m[i] - 'a'] != NULL)
			p = p->next[m[i] - 'a'];
		else
		{
			q = (link)malloc(sizeof(tree));
			for (j = 0; j < 26; j++)
				q->next[j] = NULL;
			q->end = 0;
			p->next[m[i] - 'a'] = q;
			p = q;
		}
	}
	p->end = 1;
	return;
}
void pick(char m[], char n[]) //从文章中取出单词（从 first 到 last），pos代表当前单词的首字母位置，sum_pos代表之前的总读入长度
{
	int i = 0, j = remain2;
	if (num + remain1 < 70) //防止最后一行未完全读入时，导致后面因为while里的-j使最后几个单词不读入
		j = 0;
	first = last;
	while ((m[first] < 'a' || m[first] > 'z') && first < num + remain1 - j)
		first++;
	pos = first;
	last = first;
	while ('a' <= m[last] && m[last] <= 'z' && last < num + remain1 - j)
	{
		n[i] = m[last];
		last++;
		i++;
	}
	n[i] = '\0';
}
int find(char m[]) //查询
{
	int i, j = 1;
	p = start;
	for (i = 0; i < strlen(m); i++)
	{
		if (p->next[m[i] - 'a'] != NULL)
			p = p->next[m[i] - 'a'];
		else
		{
			j = 0;
			break;
		}
	}
	return j && p->end;
}
int cmp(const void *a, const void *b) // 前大后小
{
	link_2 x = (link_2)a;
	link_2 y = (link_2)b;
	if (x->times != y->times)
		return x->times - y->times;
	else
		return strcmp(y->word, x->word);
}
void in_2(char m[]) //输入错误单词
{
	int i = 1;
	p_2 = start_2;
	while (p_2->next != NULL)
	{
		if (strcmp(p_2->word, m) == 0)
		{
			p_2->place = (int *)realloc(p_2->place, (p_2->times + 1) * sizeof(int));
			p_2->place[p_2->times] = pos + sum_pos;
			p_2->times++;
			q_2 = p_2;
			p_2->next->last = p_2->last;
			p_2->last->next = p_2->next;
			while (cmp(p_2, q_2) >= 0)
				q_2 = q_2->last;
			p_2->next = q_2->next;
			p_2->last = q_2;
			q_2->next->last = p_2;
			q_2->next = p_2;
			i = 0;
			break;
		}
		else if (strcmp(p_2->word, m) > 0 && p_2->times == 1) //提前跳出循环
			break;
		else
			p_2 = p_2->next;
	}
	if (i) //未找到单词
	{
		p_2 = (link_2)malloc(sizeof(tree_2));
		p_2->place = (int *)malloc(sizeof(int));
		strcpy(p_2->word, m);
		p_2->place[0] = pos + sum_pos;
		p_2->times = 1;
		q_2 = end_2;
		while (cmp(p_2, q_2) >= 0)
			q_2 = q_2->last;
		p_2->next = q_2->next;
		p_2->last = q_2;
		q_2->next->last = p_2;
		q_2->next = p_2;
	}
}
int main()
{
	int i, j;
	FILE *dic = fopen("dictionary.txt", "r");
	FILE *art = fopen("article.txt", "r");
	FILE *mis = fopen("misspelling.txt", "w");
	begin();
	//t1=clock();
	while (fgets(sentense, 70, dic) != NULL)
	{
		change(sentense);
		j = 1; //记录单词里有没有字符
		for (i = 0; i < strlen(sentense) - 1; i++)
			if (sentense[i] < 'a' || sentense[i] > 'z')
			{
				j = 0;
				break;
			}
		if (j == 0)
			continue;
		else
		{
			sentense[strlen(sentense) - 1] = '\0'; //去除\n
			in(sentense);
		}
	}
	while ((num = fread(sentense + remain1, sizeof(char), 70 - remain1, art)) != 0) //remain1是上次残余单词的字符长度，remain2是这次的字符长度
	{
		change(sentense);
		for (remain2 = 0; 'a' <= sentense[strlen(sentense) - remain2 - 1] && sentense[strlen(sentense) - remain2 - 1] <= 'z'; remain2++)
			;
		last = 0;
		while (1)
		{
			pick(sentense, word);
			if (word[0] == '\0')
				break;
			else
			{
				if (find(word) == 0)
					in_2(word);
			}
		}
		for (i = 0, j = 70 - remain2; i < remain2; i++, j++) //残余单词前移
			sentense[i] = sentense[j];
		sum_pos += 70 - remain2;
		remain1 = remain2;
	}
	p_2 = start_2;
	while (p_2->next != end_2)
	{
		p_2 = p_2->next;
		fprintf(mis, "%s %d", p_2->word, p_2->times);
		for (i = 0; i < p_2->times; i++)
			fprintf(mis, " %d", p_2->place[i]);
		fprintf(mis, "\n");
	}
	//t2=clock();
	printf("%ld", t2 - t1);
	system("pause");
	return 0;
}
