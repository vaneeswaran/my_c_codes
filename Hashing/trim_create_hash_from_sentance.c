/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check trim space and create hash from a given sentence 
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define INIT 0
#define SUCCESS 0
#define FAIL 1
#define MAX_WORD 30
#define MAX_CHAR 250
#define MAX_POS 10
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
char str[MAX_CHAR];
char str_dup[MAX_CHAR];
int wc=INIT;
int Last_Char=INIT;
typedef struct hash
{
		char word[MAX_WORD];
		int pos[MAX_POS];
		int pos_index;
		int occ;
}HASH_TAB;
HASH_TAB *Hash;
void Trim_Spaces(int len)
{
		int i=INIT;
		int j=INIT;
	while(i<len)
		{
				if(str[i]=='\t')
						str[i]=' ';
				i++;
		}
		i=INIT;

		while(i<len)
		{
				if(str[i]!=' ' && str[i]!='\n')
				{
						str_dup[j++]=str[i];
						Last_Char=i;
				}
				else if (str[i]==' ' && str[i+1]!=' ')
						str_dup[j++]=str[i];
				i++;
		}
		str_dup[Last_Char+ONE]='\0';
		for(i=INIT;i<Last_Char;i++)
		{
				if(str_dup[i]==' ')
						wc++;
			
		}
		if(len>ZERO)
			wc++;

}

void Create_Hash(void)
{
Hash=(HASH_TAB*)malloc(sizeof(HASH_TAB)*wc);
int i=INIT;
int j=INIT;
int flag=INIT;
int count=ONE;
char *temp;
				temp = strtok (str_dup," , ");
				  while (temp != NULL)
				    {
						j=INIT;
						flag=INIT;
						while(j<i)
						{
						if(!strcmp(temp,Hash[j].word))
						{
							Hash[j].pos[Hash[j].pos_index++]=count;
							Hash[j].occ++;
							flag=ONE;
							break;
						}
						j++;
						}
						if(flag==INIT)
						{
							Hash[i].pos[Hash[i].pos_index++]=count;
							strcpy(Hash[i].word,temp);
						
					  i++;
						}
						temp = strtok (NULL, " ,	 ");
					  count++;
					 }
			wc=i;
}
void print()
{
int i=INIT;
				fprintf(stdout,"\n----------------Total Unique Words:%d ------------------------",wc);		
	while(i<wc)
	{
	fprintf(stdout,"\n\tWord:%s  Occurence:%d in Positions",Hash[i].word,Hash[i].occ+ONE);
	int j=INIT;
	while(j<Hash[i].pos_index)
		fprintf(stdout,"%d ",Hash[i].pos[j++]);
	i++;	
	}
	fprintf(stdout,"\n-----------------------------------------------\n");

}
int main(void)
{
		int i=INIT;
		int str_len=INIT;
		fprintf(stdout,"Enter the string:");
		fgets(str,MAX_CHAR,stdin);
		str_len=strlen(str);
		Trim_Spaces(str_len);	
		//		printf("%s with Leng=%d",str_dup,strlen(str_dup));
		Create_Hash();
		print();
		return SUCCESS;
}
