#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct order{
	int mode;
	int pos;
	char string[500];
}order;
order orderlist[500];
char text[600],word[500];
int ordertop,texttop,loc;
void insert(int pos,char* str){
	int i,j=0,len=strlen(str);
	while(text[j+1]!='\0') j++;
	text[j+len+1]='\0';
	for(;j>=pos;j--){
		text[j+len]=text[j];
	}
	for(j=pos,i=0;i<len;i++){
		text[j++]=str[i];
	} 
	return;
}
void delet(int pos,int num){
	int i,j,len=strlen(text);
	if(len-pos<num) {
		for(i=0,j=pos;j<len;j++){
			word[i++]=text[j];
		}
		word[i]='\0';
		text[pos]='\0';
	}
	else {
	
		for(i=0,j=pos;j<pos+num;j++){
			word[i++]=text[j];
			text[j]=text[j+num];
		}
		for(;j<len-num;j++){
			text[j]=text[j+num];
		}
		word[i]='\0';
		text[len-num]='\0';

	}
}

int main(){
	int n,i,mod,len,num;
	gets(text);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&mod);
		ordertop++;
		orderlist[ordertop].mode=mod;
		scanf("%d%s",&orderlist[ordertop].pos,orderlist[ordertop].string);
	}
	while(scanf("%d",&mod)!=EOF){
		if(mod==-1) {
			printf("%s",text);
			system("pause");
			return 0;
		}
		else if(mod==1){
			ordertop++;
			orderlist[ordertop].mode=mod;
			scanf("%d%s",&orderlist[ordertop].pos,orderlist[ordertop].string);
			insert(orderlist[ordertop].pos,orderlist[ordertop].string);
			
		}
		else if(mod==2){
			ordertop++;
			orderlist[ordertop].mode=mod;
			scanf("%d%d",&orderlist[ordertop].pos,&num);
			delet(orderlist[ordertop].pos,num);
			strcpy(orderlist[ordertop].string,word);
			
		}
		else if(mod==3){
			if(ordertop==-1) continue;
			else if(orderlist[ordertop].mode==1){
				num=strlen(orderlist[ordertop].string);
				delet(orderlist[ordertop].pos,num);
				ordertop--;
				
			}
			else {
				insert(orderlist[ordertop].pos,orderlist[ordertop].string);
				ordertop--;
				
			}
			
		}
	}
	system("pause");
	return 0;
}
