#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char line[500];
void add(int pos,char str[500])//��line��pos��ǰ����str 
{
	int i,j;
	for(j=strlen(line);j>=pos;j--)
	{
		line[j+strlen(str)]=line[j];
	}
	for(i=0,j=pos;i<strlen(str);i++,j++)
	{
		line[j]=str[i];
	}
	
}
void del(int pos,int length)//��line��pos���󣨰���line��pos��ɾ��length���ַ� 
{
	int i,j;
	for(i=pos;i<strlen(line)+5;i++,j++)
	{
		line[i]=line[i+length];
	}
}
struct order
{
	int mode;//����ģʽ 
	int pos; 
	char str[500];
	int length;
	int del;//��¼�ò�����û�б�ɾ�� 
};
struct order did[15],doing[30];
int main()
{
	gets(line);
	int i=0,did_num=0,doing_num=0,j=0,c=0,k=0;
	scanf("%d",&did_num);
	for(i=0;i<did_num;i++)//��¼����did 
	{
		scanf("%d %d %s",&did[i].mode,&did[i].pos,did[i].str);
	}
	i=0;
	while(1)//��¼����doing 
	{
		scanf("%d",&doing[i].mode);
		if(doing[i].mode==1)
		scanf(" %d %s",&doing[i].pos,doing[i].str);
		else if(doing[i].mode==2)
		scanf(" %d %d",&doing[i].pos,&doing[i].length);
		else if(doing[i].mode==3)
		{
			
		}
		else if(doing[i].mode==-1)
		break;
		i++;
	}
	doing_num=i;
	for(i--;i>=0;i--)//��������3����ǰһ���ǡ�3������������ͬʱ��K��¼�ж��١�3"δ������ 
	{
		if(doing[i].mode==3&&doing[i].del!=666)
		{
			c=0;
			for(j=i;j>=0;j--)
			{
				if((doing[j].mode==1||doing[j].mode==2)&&doing[j].del!=666)
				{
					doing[i].del=666;
					doing[j].del=666;
					c=1;
					break;
				}
			}
			if(c==0)
			k++;
		}
	}
	for(i=did_num-1,j=0;j<k;i--,j++)//����K�������did 
	{
		if(did[i].mode==1)
		{
			
			del(did[i].pos,strlen(did[i].str));
			
		}
		else if(did[i].mode==2)
		{
			add(did[i].pos,did[i].str);
		}
	}
	for(i=0;i<doing_num;i++)//�������δ��ɾ����doing 
	{
		if(doing[i].mode==1&&doing[i].del!=666)
		{
			add(doing[i].pos,doing[i].str);
		}
		else if(doing[i].mode==2&&doing[i].del!=666)
		{
			del(doing[i].pos,doing[i].length);
		}
	}
	puts(line);
	system("pause");
	return 0;
}
