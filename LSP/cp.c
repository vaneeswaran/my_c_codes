/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code is the implementation of traditional cp (copy) command in UNIX
#			 	
#
*/

#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define SUCCESS 0
#define FAIL 1
#define INIT 0
#define TRUE 1
#define FALSE 0
#define MAX_BUFFER 100
#define FILE_PRESENT 1
#define FILE_NPRESENT 0
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
int force_flag=FALSE;
int dir_flag=FALSE;
int check_file(char *filename)
{
		FILE *fp=NULL;
		int flag=INIT;
		fp=fopen(filename,"r");
		if(fp!=NULL)
		{
				flag= FILE_PRESENT;
				fclose(fp);
		}
		else 
		{
				flag= FILE_NPRESENT;
				fprintf(stdout,"\nERROR:File %s Not Present",filename);
		}
		return flag;
}
int check_arg(int argc,char*argv[])
{
		int st=ONE;
		if(argc<=TWO)
		{
				fprintf(stdout,"Error:More Arguments Expected:\n");
				return FAIL;
		}
		else if(!(strcmp(argv[ONE],"-f")))
		{
				if(argc<=THREE)
				{
						fprintf(stdout,"Error:More Arguments Expected:\n");
						return FAIL;
				}
				else 
				{
						force_flag =TRUE;
						st=TWO;
						if(argc>FOUR)
						{
								dir_flag=TRUE;
						}
				}
		}
		else 
		{
				if(argc>=FOUR)
				{
						dir_flag=TRUE;
				}

		}
		int i=INIT;

		for(i=st;i<argc-TWO;i++)
				if(check_file(argv[i])==FILE_NPRESENT)
						return FAIL;
		return SUCCESS;
}
void file_copy(int argc,char *argv[])
{
		int tmp=INIT;
		char ch;
		if(dir_flag==FALSE)
		{
				if(force_flag==FALSE && fopen(argv[argc-ONE],"r")!=NULL)
						fprintf(stdout,"Error:Dest File Already Present use -f\n");
				else
				{
						FILE *Source=NULL,*Dest=NULL;
						if(force_flag==TRUE)
								tmp=TWO;
						else
								tmp=ONE;
						Source=fopen(argv[tmp],"r");
						Dest=fopen(argv[argc-ONE],"w+");
						while( ( ch = fgetc(Source) ) != EOF )
								fputc(ch, Dest);
						fprintf(stdout,"\nFile Copied Successfully\n");
				}
		}
		else
		{
				struct stat s;
				int err = stat(argv[argc-ONE], &s);
				char des_str[MAX_BUFFER];
				int tmp_dir_flag=FALSE;
				if(S_ISDIR(s.st_mode))
						tmp_dir_flag=TRUE;
				if (force_flag == TRUE && tmp_dir_flag == FALSE)
				{
						tmp_dir_flag = TRUE;
						mkdir(argv[argc-ONE],0777);
				}
				if(tmp_dir_flag == TRUE )
				{

						if(force_flag==TRUE)
								tmp=TWO;
						else
								tmp=ONE;
						int i=INIT;
						for(i=tmp;i<argc-ONE;i++)
						{
								sprintf(des_str,"%s/%s",argv[argc-ONE],argv[i]);
								if(force_flag==FALSE && fopen(des_str,"r")!=NULL)
										fprintf(stdout,"Error:Dest File %s Already Present in %s, use -f:Skipping\n",argv[i],argv[argc-ONE]);
								else	
								{
										FILE *Source=NULL,*Dest=NULL;
										Source=fopen(argv[i],"r");
										Dest=fopen(des_str,"w+");
										while( ( ch = fgetc(Source) ) != EOF )
												fputc(ch, Dest);

								}
						}


				} else {
						fprintf(stdout,"Error:Directory %s Not Present\n",argv[argc-ONE]);
				}

		}

}
int main(int argc,char *argv[])
{
		if(check_arg(argc,argv)==FAIL)
				return FAIL;
		file_copy(argc,argv);
		return SUCCESS;
}
