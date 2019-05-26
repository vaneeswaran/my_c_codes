/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code is implementation of string reverse 
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
void Str_Rev(int str_len)
{
		int st=INIT,end=str_len-1;
		char temp='\0';
		while(st<end)
		{
			temp=Buffer[st];
			Buffer[st]=Buffer[end];
			Buffer[end]=temp;
			st++;
			end--;
		}

}
int main(void)
{
		int str_len=INIT;
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
		Str_Rev(str_len);
		fprintf(stdout,"Reversed String:%s\n",Buffer);

		return SUCCESS;
}
