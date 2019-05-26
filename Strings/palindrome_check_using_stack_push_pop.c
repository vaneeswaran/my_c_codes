/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check a string is palindrome or not by using push and pop operations in stack 
*/

#include<stdio.h>
#include<malloc.h>
#include<errno.h>
#define SUCCESS 0
#define INIT 0
#define MAX_BUFFER 50
#define FAIL 1
#define INIT_STACK -1
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

extern int errno;
char *Buffer=NULL;

struct Stack
{
		char stk[MAX_BUFFER];
		int top;
}stack;

int My_Str_Len(void)
{
		int i=INIT;
		while(Buffer[i]!='\0')
				i++;
		return i-ONE;
}
void push(char data)
{
		if(stack.top==MAX_BUFFER-ONE)
				fprintf(stdout,"Error:Cannot Perform Push:Stack Full\n");
		else
				stack.stk[stack.top++]=data;
}
char pop(void)
{
		if(stack.top==INIT_STACK)
				fprintf(stdout,"Error:Cannot Perform Push:Stack Empty\n");
		else
				return stack.stk[stack.top--];
}
void check_palindrome(int str_len)
{
		int i =INIT;
		int stk_mid = str_len/TWO;
		int flag=INIT;
		while(i<stk_mid)
		push(Buffer[i++]);
		if(str_len%TWO!=ZERO)
		i++;
		while(i<str_len)
		if(!(Buffer[i++]==pop()))
		{
			flag=ONE;
			break;
		}
		flag==ONE?fprintf(stdout,"Palindrome\n"):fprintf(stdout,"Not a Palindrome\n");

}
int main(void)
{
		int str_len=INIT;
		stack.top=INIT_STACK;
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
		(str_len==ONE)?fprintf(stdout,"Palindrome\n"):check_palindrome(str_len);
		return SUCCESS;
}
