/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will count the number of occurence of each char in a string
*/
#include<stdio.h>
#include<string.h>
#define INIT 0
#define SUCCESS 0
#define FAIL 1
#define MAX_CHAR 50
#define MAX_REC 128
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

	char str[MAX_CHAR];
	short int Hash_Occur[MAX_REC];

void Print_Data(void)
{
int i=INIT;
while(i<MAX_REC)
{
if(Hash_Occur[i]>ONE && i!='\n')
	fprintf(stdout,"Duplicate Occurence of %c is %d\n",i,Hash_Occur[i]);
i++;
}
}
int main(void)
{
	int i=INIT;
	int str_len=INIT;
	fprintf(stdout,"Enter the string:");
	fgets(str,MAX_CHAR,stdin);
		str_len=strlen(str);
		for(i=INIT;i<str_len;i++)
		{
		//	if(i!='\n' && i!='\0')
				Hash_Occur[str[i]]+=ONE;
		}
	Print_Data();
	return SUCCESS;
}
