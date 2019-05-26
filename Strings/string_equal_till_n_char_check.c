/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check till how many char the given two strings are equal using 
#		my_string_compare and my_string_Ncompare 
*/

#include<stdio.h>
#include<malloc.h>
#include<errno.h>
#define SUCCESS 0
#define INIT 0
#define MAX_BUFFER 50
#define FAIL -1
#define STR_CMP_FAIL 1
#define RET_REF 10
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

extern int errno;


int My_Str_Len(char * Buffer)
{
		int i=INIT;
		while(Buffer[i]!='\0')
				i++;
		return i-ONE;
}


int My_String_NCompare(char *Buffer_1,char *Buffer_2,int N)
{
int i=INIT;
int flag=INIT;
while(i<N)
	Buffer_1[i]==Buffer_2[i++]?SUCCESS:flag++;		
if(flag>=STR_CMP_FAIL)
	return FAIL;
else return SUCCESS;
}

int My_String_Compare(char *Buffer_1,char *Buffer_2)
{
		int str_len_1=INIT,str_len_2=INIT;
		int i=INIT;
		int flag=INIT;
		str_len_1=My_Str_Len(Buffer_1);
		str_len_2=My_Str_Len(Buffer_2);
		if(str_len_1==str_len_2)
		{
		while(i<str_len_1)
			(Buffer_1[i]==Buffer_2[i++])?ZERO:flag++;
		}
		else
		flag=STR_CMP_FAIL;
			if(flag>=STR_CMP_FAIL)
			{
			i=INIT;
				while(i<str_len_1 && i<str_len_2)
					{
					flag=My_String_NCompare(Buffer_1,Buffer_2,i+ONE);
					if(flag==FAIL)
						if (i==ZERO)
							return FAIL;
						else return i+RET_REF;	
					else
						i++;
					}
				return i+RET_REF;
			}
			else
				return SUCCESS;
}
int main(void)
{
		char *Buffer_1=NULL;
		char *Buffer_2=NULL;
		int flag=INIT;
		Buffer_1=(char*)malloc(sizeof(char)*MAX_BUFFER);
		Buffer_2=(char*)malloc(sizeof(char)*MAX_BUFFER);
		//To handle error while malloc
		if (Buffer_1==NULL || Buffer_2==NULL )
		{
				perror("ERROR");
				return FAIL;
		}
		fprintf(stdout,"\nEnter the string 1: ");
		fgets(Buffer_1,MAX_BUFFER-ONE,stdin);
		fprintf(stdout,"\nEnter the string 2: ");
		fgets(Buffer_2,MAX_BUFFER-ONE,stdin);
		 flag=My_String_Compare(Buffer_1,Buffer_2);
		 (flag==SUCCESS)?fprintf(stdout,"Strings are Equal\n"):((flag==FAIL)?fprintf(stdout,"Strings are Not Equal\n"):fprintf(stdout,"Strings are Equal till First %d Characters\n",(flag-RET_REF)));
		return SUCCESS;
}
