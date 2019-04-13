#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
FILE *in, *get, *out;
typedef struct tree
{
	int judge;
	struct tree *next[26];
} tree;
typedef struct mistake
{
	char word[50];
	int num;
	int *loc;
	struct mistake *next;
} mistake;
mistake head;

tree headnode, *ptr;
int miscount = 0;

void exchange(mistake *a1, mistake *a2, mistake *b1, mistake *b2);
void sort(mistake *p);
int search(char *s);
void insert(char *s, int location);

int main()
{
	head.next = NULL;
	head.num = 99999;
	head.loc = NULL;
	strcpy(head.word, "0000");
	in = fopen("dictionary.txt", "r");
	get = fopen("article.txt", "r");
	out = fopen("misspelling.txt", "w");
	char s[50];
	int i, j, k, loc = 0, sign = 0;
	for (i = 0; i < 26; i++)
		headnode.next[i] = NULL;
	headnode.judge = 0;
	while (fscanf(in, "%s", s) != EOF)
	{
		sign = 0;
		ptr = &headnode;
		for (i = 0; s[i] != '\0'; i++)
		{
			s[i] = tolower(s[i]);
			if (!(s[i] >= 'a' && s[i] <= 'z'))
			{
				sign = -1;
				break;
			}
		}
		if (sign == -1)
			continue;
		for (i = 0; s[i] != '\0'; i++)
		{

			j = s[i] - 'a';
			if (ptr->next[j] == NULL)
			{
				tree *node = (tree *)malloc(sizeof(tree));
				for (k = 0; k < 26; k++)
					node->next[k] = NULL;
				node->judge = 0;
				ptr->next[j] = node;
				ptr = node;
			}
			else
			{
				ptr = ptr->next[j];
			}
		}
		ptr->judge = 1;
	}
	char line[2000];
	while (fgets(line, 1999, get) != NULL)
	{
		char load[50];
		int len = strlen(line);
		for (i = 0; i < len; i++)
		{
			line[i] = tolower(line[i]);
		}
		i = 0;
		while (i < len - 1)
		{
			j = 0;
			while (line[i] >= 'a' && line[i] <= 'z')
			{
				load[j++] = line[i++];
			}
			load[j] = '\0';
			if (search(load) == 0)
			{
				int fin = loc + i - j;
				insert(load, fin);
			}
			i++;
		}
		loc += len;
	}
	mistake *p = head.next;
	while (p != NULL)
	{
		fprintf(out, "%s %d %d", p->word, p->num, p->loc[0]);
		for (j = 1; j < p->num; j++)
		{
			fprintf(out, " %d", p->loc[j]);
		}
		fprintf(out, "\n");
		p = p->next;
	}
	fclose(in);
	fclose(get);
	fclose(out);
}
int search(char *s)
{
	tree *p = &headnode;
	int i, j;
	for (i = 0; s[i] != '\0'; i++)
	{
		j = s[i] - 'a';
		if (p->next[j] == NULL)
		{
			return 0;
		}
		else
			p = p->next[j];
	}
	if (p->judge == 1)
		return 1;
	else
		return 0;
}
void insert(char *s, int location)
{
	mistake *p = &head, *r = NULL, *q, *p1;
	if (!(s[0] >= 'a' && s[0] <= 'z'))
		return;
	if (p->next == NULL)
	{
		q = (mistake *)malloc(sizeof(mistake));
		q->next = NULL;
		strcpy(q->word, s);
		q->num = 1;
		q->loc = (int *)malloc(sizeof(int));
		q->loc[0] = location;
		p->next = q;
		return;
	}
	while (p != NULL)
	{
		if (strcmp(p->word, s) == 0)
		{
			p->loc = (int *)realloc(p->loc, (p->num + 1) * sizeof(int));
			p->loc[p->num] = location;
			p->num++;
			sort(p);
			return;
		}
		r = p, p = p->next;
	}

	if (p == NULL)
	{
		q = (mistake *)malloc(sizeof(mistake));
		strcpy(q->word, s);
		q->num = 1;
		q->loc = (int *)malloc(sizeof(int));
		q->loc[0] = location;
		q->next = NULL;
		p1 = head.next, r = &head;
		while (p1 != NULL && p1->num > 1)
		{
			r = p1;
			p1 = p1->next;
		}
		if (p1 == NULL)
		{
			r->next = q;
			return;
		}
		else
		{
			while (p1 != NULL && strcmp(p1->word, q->word) < 0)
				r = p1, p1 = p1->next;
			if (p1 == NULL)
				r->next = q;
			else
			{
				q->next = p1;
				r->next = q;
			}
			return;
		}
	}
}
void sort(mistake *q)
{
	mistake *a1 = &head;
	mistake *a2 = head.next, *b1 = &head;
	while (a2 != q && a2->num > q->num)
	{
		a1 = a2;
		a2 = a2->next;
	}
	if (a2 == q)
	{
		return;
	}
	else
	{
		if (a2->num < q->num)
		{
			while (b1->next != q)
				b1 = b1->next;
			a1->next = q;
			b1->next = q->next;
			q->next = a2;
			return;
		}
		else if (a2->num == q->num)
		{
			if (strcmp(a2->word, q->word) > 0)
			{
				b1 = &head;
				while (b1->next != q)
					b1 = b1->next;
				a1->next = q;
				b1->next = q->next;
				q->next = a2;
				return;
			}
			else
			{
				b1 = &head;
				while (b1->next != q)
					b1 = b1->next;
				while (a2 != q && a2->num == q->num && strcmp(a2->word, q->word) < 0)
					a1 = a2, a2 = a2->next;
				if (a2 == q)
					return;
				a1->next = q;
				b1->next = q->next;
				q->next = a2;
				return;
			}
		}
	}
}
