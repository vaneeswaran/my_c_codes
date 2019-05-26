/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check for sub string in the given string 
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



int My_String_Compare(char *Buffer_1,char *Buffer_2)
{
		int str_len_1=INIT,str_len_2=INIT;
		int i=INIT;
		int j=INIT;
		int flag=INIT;
		str_len_1=My_Str_Len(Buffer_1);
		str_len_2=My_Str_Len(Buffer_2);
		for (i = ZERO; i <= str_len_1 - str_len_2; i++)
		 {
		  for (j = i; j < i + str_len_2; j++)
		   {
		    flag = ONE;
		    if (Buffer_1[j] != Buffer_2[j - i])
		      {
		         flag = ZERO;
		         break;
		      }
		    }
		     if (flag == ONE)
		         break;
		   }
return flag;


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
		fprintf(stdout,"\nEnter the string: ");
		fgets(Buffer_1,MAX_BUFFER-ONE,stdin);
		fprintf(stdout,"\nEnter the sub string: ");
		fgets(Buffer_2,MAX_BUFFER-ONE,stdin);
		 flag=My_String_Compare(Buffer_1,Buffer_2);
		 (flag==SUCCESS)?fprintf(stdout,"Sub String Not Found\n"):fprintf(stdout,"Sub String Found\n");
		return SUCCESS;
}
