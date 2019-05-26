/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check whether the given machine is little endian or big endian
#			 
*/

#include<stdio.h>
#define SUCCESS 0
#define SET 1
#define LITTLE_ENDIAN 1
#define BIG_ENDIAN 0

int main(void)
{
unsigned int flag = SET;
char *check = (char*) &flag;
(((*check)=LITTLE_ENDIAN)?fprintf(stdout,"Machine is running on Little Endian\n"):fprintf(stdout,"Machine is running on Big Endian\n"));
return SUCCESS;
}
