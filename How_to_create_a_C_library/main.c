/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		Sample project to demonstrate how to write a C library , build as a shared library and use it 
#      	This file main.c invokes the function from the shared library
*/
#include<stdio.h>
#include<string.h>
#include"vanees.h"
char *ad[10],*fd[10];
int ai=0,fi=0;
int main()
{
ad[ai]=NULL;
fd[ai]=NULL;
char *str;
str=String_Create(10);
	ad[ai++]=str;
strcpy(str,"vaneeswaran");
printf("\nString Bef Rev:%s",str);
String_Reverse(str);
printf("\nString After Rev:%s\n",str);
	fd[fi++]=str;
String_Delete(str);
return Mem_Check();
}
