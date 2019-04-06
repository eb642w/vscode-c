#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char line[500];
void add(int pos,char str[500])//在line【pos】前添加str 
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
void del(int pos,int length)//在line【pos】后（包括line【pos】删除length个字符 
{
	int i,j;
	for(i=pos;i<strlen(line)+5;i++,j++)
	{
		line[i]=line[i+length];
	}
}
struct order
{
	int mode;//操作模式 
	int pos; 
	char str[500];
	int length;
	int del;//记录该操作有没有被删除 
};
struct order did[15],doing[30];
int main()
{
	gets(line);
	int i=0,did_num=0,doing_num=0,j=0,c=0,k=0;
	scanf("%d",&did_num);
	for(i=0;i<did_num;i++)//记录操作did 
	{
		scanf("%d %d %s",&did[i].mode,&did[i].pos,did[i].str);
	}
	i=0;
	while(1)//记录操作doing 
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
	for(i--;i>=0;i--)//将操作“3”与前一个非“3”操作抵消，同时用K记录有多少“3"未被消除 
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
	for(i=did_num-1,j=0;j<k;i--,j++)//根据K反向操作did 
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
	for(i=0;i<doing_num;i++)//正向操作未被删除的doing 
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

