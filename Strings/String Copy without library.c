/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code is implementation of string copy 
*/

#include<stdio.h>
#include<malloc.h>
#include<errno.h>

#define SUCCESS 0
#define INIT 0
#define MAX_BUFFER 50
#define FAIL 1
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
extern int errno;
char *Buffer=NULL;
int My_Str_Len(void)
{
		int i=INIT;
		while(Buffer[i]!='\0')
				i++;
		return i-ONE;
}
char* My_Str_Cpy(int str_len)
{
		char *str;
		int i=INIT;
		str=(char*)malloc(sizeof(char)*str_len+ONE);
				//To handle error while malloc
		if (str==NULL)
		{
				perror("ERROR:String Copy Failed");
				return NULL;
		}

		while(Buffer[i]!='\0')
			str[i]=Buffer[i++];
			str[i]='\0';

return str;
}
int main(void)
{
		int str_len=INIT;
		char *copy_str;
		Buffer=(char*)malloc(sizeof(char)*MAX_BUFFER);
				//To handle error while malloc
		if (Buffer==NULL)
		{
				perror("ERROR");
				return FAIL;
		}
		fprintf(stdout,"\nEnter the string");
		fgets(Buffer,MAX_BUFFER-ONE,stdin);
		str_len=My_Str_Len();
		fprintf(stdout,"String Length:%d\n",str_len);
		copy_str=My_Str_Cpy(str_len);
		if (copy_str==NULL)
		return FAIL;
		
		fprintf(stdout,"Org_Str:  Address:%u  String:%s",Buffer,Buffer);
		fprintf(stdout,"Dup_Str:  Address:%u  String:%s",copy_str,copy_str);
		return SUCCESS;
}
