/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		Sample project to demonstrate how to write a C library , build as a shared library and use it 
#      	This file vanees_string.c has the implementation of the functions that are used in the shared library
*/

#include"vanees.h"
#include<stdio.h>
#include<malloc.h>
#include<errno.h>
#define MEM_LEAK 1
#define NO_MEM_LEAK 0
#define INIT 0
#define MAX 10
enum numbers{ZERO,ONE};
static char *am[MAX],*fm[MAX];
static int ai=INIT,fi=INIT;
char *String_Create(int Str_Len)
{
		char *str=NULL;
		str=(char*)malloc(sizeof(char)*Str_Len);
		if(str==NULL)
				perror("Error:");
		else
				am[ai++]=str;
		return str;	
}
void String_Delete(char *String)
{
		if(String!=NULL)
				fm[fi++]=String;
		free(String);
}
void String_Reverse(char *String)
{


		int i=INIT;
		int st=INIT,end=INIT;
		while(String[i]!='\0')
				i++;
		end= i-ONE;

		char temp='\0';
		while(st<end)
		{
				temp=String[st];
				String[st]=String[end];
				String[end]=temp;
				st++;
				end--;
		}

}

int Mem_Check()
{
		int i,j;
		int temp_ai=ai;
		int temp_fi=fi;
		for(i=INIT;i<temp_ai;i++)
		{
				for(j=INIT;j<temp_fi;j++)
				{
						if(am[i]==fm[j])
						{
								am[i]=NULL;
								ai-=ONE;
						}
				}
		}
if(ai!=ZERO)
{
printf("\nMemory Leak Found:\n");

		for(i=INIT;i<temp_ai;i++)
		{
		if(am[i]!=NULL)
		printf("Memory Allocated : %u Not Freed\n",am[i]);
return MEM_LEAK;
}
return NO_MEM_LEAK;
}
}

