/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code is the implementation of traditional cat command in UNIX
#			 	
#
*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define SUCCESS 0
#define FAIL -1
#define INIT 0
#define TRUE 1
#define FALSE 0
#define MAX_BUFFER 200
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
FILE *input;
FILE *output;
int check_arg(int argc,char*argv[])
{
		output= stdout;
		if (argc == ONE)
				input=stdin;
		else
		{
				input = fopen(argv[argc-ONE],"r");
				if (input == NULL)
				{

						fprintf(stdout,"\nERROR:File %s Not Present",argv[argc-ONE]);
						return FAIL;
				}	
		}
		return SUCCESS;
}
int file_copy(FILE* infd,FILE* outfd,int buffersize)
{
		char *buf;
		char ch;
		int i =INIT;
		int j=INIT;
		buf=(char *) malloc(sizeof(char)*buffersize);
		if(buf == NULL)
		{
				fprintf(stdout,"ERROR:Memory Allocation Failed");
				return FAIL;
		}
		if (infd !=stdin)
		while( ( ch = fgetc(infd) ) != EOF )
				 buf[i++]=ch;
		else
		while( ( ch = fgetc(infd) ) != '\n' )
				 buf[i++]=ch;

		while( j<=i )
				 fputc(buf[j++],outfd);

		free(buf);
}
int main(int argc,char *argv[])
{
		if(check_arg(argc,argv)==FAIL)
				return FAIL;
		file_copy(input,output,MAX_BUFFER);
		return SUCCESS;
}
