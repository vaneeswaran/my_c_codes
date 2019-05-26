/*
   Assumptions Made:
   1)The Inputs for the program is given in the form of file and given as command line argumnt
   2)The file contains 20 lines where first ten lines will hold the info about 10 wafers in stack 1 
   3)the next 10 lines will hold the info of 10 wafer in stack 2
   4)Format of Each Line Should be in given format
   Note W&R-> Washing and Rinsing
   <Wafer Nane> <W&R1 Time> <Electroplating> <W&R2 Time>
eg:
Sio2 10 10 20
Geo2 20 3 10
5)The overall time is displayed in cli whereas the information about process scheduling for each wafer is given in output file
6)It is assumed that the wafers from the stack can be taken in random order
7)Unit of Time is considered as Minutes
8)It is assumed that the data's in the file are valid one
 */
#include<stdio.h>
#include<malloc.h>
#define SUCCESS 0
#define FAIL 1
#define MAX_CHAR 50
#define MAX_BUFFER 100
#define MAX_STACK 10
#define INIT 0
#define STACK_INIT -1
#define COMPLETE 1
#define NOT_COMPLETE 0
#define TRUE 1
#define FREE 0
#define FULL 1
#define THIRD_JOB 3
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

typedef struct WAFERS
{
		char *name[MAX_CHAR];
		int wr1;
		int wr2;
		int ep;
		int flag;
		int total;
}WAFER;
WAFER *Stack1,*Stack2;
typedef struct data
{
		WAFER *Stack;
		int Time;
}DATA;

// Global Variables 
DATA SD1,SD2;//Stack Buffers
DATA SD;//for temproey Stack buffer for processing
int WR1,WR2,WR3,WR4,WR5,WR6;
int EP1,EP2;
int FREE_W1,FREE_W2,FREE_EP;
//End of Global Variable

void read_file(FILE* fp)
{
		int i;
		char str[MAX_BUFFER],temp[MAX_BUFFER];
		fgets(temp,MAX_BUFFER,fp);
		fgets(temp,MAX_BUFFER,fp);
		for(i=INIT;i<MAX_STACK;i++)
		{
				fscanf(fp,"%s",Stack1[i].name);
				fscanf(fp,"%d %d %d",&Stack1[i].wr1,&Stack1[i].ep,&Stack1[i].wr2);
			Stack1[i].flag=NOT_COMPLETE;
			Stack1[i].total=Stack1[i].wr1 + Stack1[i].ep + Stack1[i].wr2;
		}
		fgets(temp,MAX_BUFFER,fp);
		fgets(temp,MAX_BUFFER,fp);
		fgets(temp,MAX_BUFFER,fp);
		for(i=INIT;i<MAX_STACK;i++)
		
		{
				fscanf(fp,"%s",Stack2[i].name);
				fscanf(fp,"%d %d %d",&Stack2[i].wr1,&Stack2[i].ep,&Stack2[i].wr2);
			Stack2[i].flag=NOT_COMPLETE;
			Stack2[i].total=Stack2[i].wr1 + Stack2[i].ep + Stack2[i].wr2;
		}

		/*
		   for(i=INIT;i<MAX_STACK;i++)
		   {
		   fprintf(stdout,"Stack 1: %s   %d  %d %d  \t",Stack1[i].name,Stack1[i].wr1,Stack1[i].ep,Stack1[i].wr2);
		   fprintf(stdout,"Stack 2: %s   %d  %d %d",Stack2[i].name,Stack2[i].wr1,Stack2[i].ep,Stack2[i].wr2);
		   fprintf(stdout,"\n");

		   }
		 */
}

void INIT_Data(void)
{
		WR1=STACK_INIT;
		WR2=STACK_INIT;
		WR3=STACK_INIT;
		WR4=STACK_INIT;
		WR5=STACK_INIT;
		WR6=STACK_INIT;
		EP1=STACK_INIT;
		EP2=STACK_INIT;
		FREE_EP=TWO;
		FREE_WR1=ONE;
		FREE_WR2=THREE;
		WR1=ONE;//allocating 1 and 2 as default jobs
		WR2=TWO;
}


int Process_Data(void)
{
		int timer=INIT;
		INIT_Data();
		while(TRUE)
		{
		if(WR1!=STACK_INIT)
		SD[WR1].

		timer++;
		}
		return timer;
}
int main(int argc,char * argv[])
{
		int temp=MAX_CHAR;
		FILE * fp=NULL;
		if(argc<TWO | argc>TWO)
		{
				fprintf(stdout,"\nError:Invalid Arguments\nExpected: exe input_filename\n:");
				return FAIL;
		}

		fprintf(stdout,"\nProcessing Data:\n");
		fp=fopen(argv[ONE],"r");
		if(fp==NULL)
		{
				perror("Error:");
				return FAIL;
		}
		else
		{
				Stack1=(WAFER*)malloc(sizeof(WAFER*)*MAX_STACK);
				Stack2=(WAFER*)malloc(sizeof(WAFER*)*MAX_STACK);
				if(Stack1==NULL | Stack2==NULL)
				{
						perror("Error:");
						return FAIL;
				}
				read_file(fp);
				SD1.Stack=Stack1;
				SD2.Stack=Stack2;
				SD1.Time=INIT;
				SD2.Time=INIT;
				SD=SD1;
				SD1.Time=Process_Data();
				SD=SD2;
				SD2.Time=Process_Data();

		}
}
