/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will perform the shecduler operation whereas the input is given in the form as mentioned below
#			
#

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
9)input file is input and output is displayed on stdout
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
#define FALSE 0
#define FREE 0
#define FULL 1
#define THIRD_JOB 3
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
int W1[MAX_STACK],W2[MAX_STACK],EP[MAX_STACK];
int W1L,W2L,EPL;
int TICK=INIT;
int cstat=INIT;
int c1stat=INIT;
int c2stat=INIT;
typedef struct WAFERS
{
		char *name[MAX_CHAR];
		int wr1;
		int wr2;
		int ep;
		int twr1;
		int twr2;
		int tep;
		int w1_in,w1_out;
		int w2_in,w2_out;
		int ep_in,ep_out;
		int eflag;
		int wflag;

}WAFER;
WAFER *Stack1,*Stack2,*Stack;


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
				Stack1[i].twr1=Stack1[i].wr1;
				Stack1[i].tep=Stack1[i].ep;
				Stack1[i].twr2=Stack1[i].wr2;
		}
		fgets(temp,MAX_BUFFER,fp);
		fgets(temp,MAX_BUFFER,fp);
		fgets(temp,MAX_BUFFER,fp);
		for(i=INIT;i<MAX_STACK;i++)

		{
				fscanf(fp,"%s",Stack2[i].name);
				fscanf(fp,"%d %d %d",&Stack2[i].wr1,&Stack2[i].ep,&Stack2[i].wr2);
				Stack2[i].twr1=Stack2[i].wr1;
				Stack2[i].tep=Stack2[i].ep;
				Stack2[i].twr2=Stack2[i].wr2;
		}

}

void INIT_Data(void)
{
		int i;

		for(i=ZERO;i<MAX_STACK;i++)
		{
				W1[i]=i;//Default assigning all task to buffer 1
				W2[i]=STACK_INIT;
				EP[i]=STACK_INIT;
				Stack[i].w1_in=INIT;
				Stack[i].eflag=NOT_COMPLETE;
				Stack[i].wflag=NOT_COMPLETE;

		}
		W1L=MAX_STACK;
		W2L=INIT;
		EPL=INIT;
		cstat=INIT;
		c1stat=INIT;
		c2stat=INIT;
}
int check(int i,int Timer)
{

		int j=INIT;
		int iptr=INIT;
		iptr=W1[i];
		if(Stack[iptr].wr1-TICK>ZERO)
		{
				Stack[iptr].wr1-=TICK;
				return TRUE;
		}
		else if(Stack[iptr].wr1==ZERO)
		{
				Stack[iptr].w1_out=Timer;
				EP[EPL]=W1[i];
				Stack[W1[i]].ep_in=Timer;
				EPL+=ONE;
				for(j=i;j<W1L-ONE;j++)
						W1[j]=W1[j+ONE];
				W1L-=ONE;
				return FALSE;
		}
		else if(Stack[iptr].wr1-TICK==ZERO)
		{
				Stack[iptr].wr1-=TICK;
				Stack[iptr].w1_out=Timer;
				EP[EPL]=W1[i];
				Stack[W1[i]].ep_in=Timer;
				EPL+=ONE;
				for(j=i;j<W1L-ONE;j++)
						W1[j]=W1[j+ONE];
				W1L-=ONE;
				cstat=TRUE;
				return TRUE;
		}

}
int check1(int i,int Timer)
{

		int j=INIT;
		int iptr=INIT;
		iptr=EP[i];

		if(Stack[iptr].ep-TICK>ZERO)
		{
				Stack[iptr].ep-=TICK;
				return TRUE;
		}
		else if(Stack[iptr].ep==ZERO)
		{
				Stack[iptr].ep_out=Timer;
				W2[W2L]=EP[i];
				Stack[iptr].w2_in=Timer;
				W2L+=ONE;
				for(j=i;j<EPL-ONE;j++)
						EP[j]=EP[j+ONE];
				EPL-=ONE;
				return FALSE;
		}	
		else if(Stack[iptr].ep-TICK==ZERO)
		{
				Stack[iptr].ep_out=Timer;
				W2[W2L]=EP[i];
				Stack[iptr].w2_in=Timer;
				W2L+=ONE;
				for(j=i;j<EPL-ONE;j++)
						EP[j]=EP[j+ONE];
				EPL-=ONE;
				c1stat=TRUE;
				return TRUE;
		}	
}

int check2(int i,int Timer)
{

		int j=INIT;
		int iptr=INIT;
		iptr=W2[i];
		if(Stack[iptr].wr2-TICK>ZERO)
		{
				Stack[iptr].wr2-=TICK;
				return TRUE;
		}
		else if(Stack[iptr].wr2==ZERO)
		{
				Stack[iptr].w2_out=Timer;
				for(j=i;j<W2L-ONE;j++)
						W2[j]=W2[j+ONE];
				W2L-=ONE;
				return FALSE;
		}
		else if(Stack[iptr].wr2-TICK==ZERO)
		{
				Stack[iptr].w2_out=Timer;
				for(j=i;j<W2L-ONE;j++)
						W2[j]=W2[j+ONE];
				W2L-=ONE;
				c2stat=TRUE;
				return TRUE;
		}


}

int Proc_Data()
{
		int Timer=ONE;
		int w1i=INIT;
		int w2i=INIT;
		int epi=INIT;
		int cur_w1=INIT;
		int cur_ep=INIT;
		int cur_w2=INIT;

		//Processing Buffer 1
		int count=INIT;	
		INIT_Data();
		while(TRUE)
		{
				while(count<THREE)
				{

						if(cur_w1<W1L)
						{
								cstat=INIT;
								if(check(w1i,Timer)!=TRUE)
								{
										int old=w1i;	
										while(TRUE && W1L!=ZERO)
										{
												cstat=INIT;
												if(check(w1i,Timer))
												{
														if(cstat!=TRUE)
																w1i++;

														if(w1i>=W1L)
																w1i=ZERO;
														break;
												}
												if(w1i>=old)
														break;
												if(w1i>=W1L)
														w1i=ZERO;

										}
								}
								else
								{
										if(cstat!=TRUE)
												w1i++;
										if(w1i>=W1L)
												w1i=ZERO;

								}
								cur_w1++;
						}
						count++;
				}
				while(count<FIVE)
				{
						if(cur_ep<EPL)
						{
								c1stat=INIT;
								if(Stack[EP[epi]].ep_in!=Timer)
								{
										int old1=epi;

										if(check1(epi,Timer)!=TRUE)
										{
												int old=epi;
												while(TRUE && EPL!=ZERO )
												{
														c1stat=INIT;
														if(check1(epi,Timer))
														{
																if(c1stat!=TRUE)
																		epi++;
																if(epi>=EPL)
																		epi=ZERO;
																break;
														}
														if(epi>=old)
																break;
														if(epi>=EPL)
																epi=ZERO;
												}
										}
										else
										{
												if(c1stat!=TRUE)
														epi++;


												if(epi>=EPL)
														epi=ZERO;

										}
								}
								else
								{
										epi++;
										if(epi>=EPL)
												epi=ZERO;
								}
								cur_ep++;
						}
						count++;
				}
				while(count<EIGHT)
				{
						if(cur_w2<W2L)
						{
								c2stat=INIT;

								if(Stack[W2[w2i]].w2_in!=Timer)
								{
										if(check2(w2i,Timer)!=TRUE)
										{
												int old=w2i;
												while(TRUE && W2L!=ZERO)
												{
														c2stat=INIT;
														if(check2(w2i,Timer))
														{
																if(c2stat!=TRUE)
																		w2i++;

																if(w2i>=W2L)
																		w2i=ZERO;
																break;
														}
														else
																w2i++;
														if(old>=w2i)
																break;
														if(w2i>=W2L)
																w2i=ZERO;
												}
										}
										else
										{
												if(c2stat!=TRUE)
														w2i++;
												if(w2i>=W2L)
														w2i=ZERO;
										}
								}
								else
								{
										w2i++;
										if(w2i>=W2L)
												w2i=ZERO;
								}
						cur_w2++;
						}
						count++;
				}
				count=ZERO;
				Timer++;
				if(W1L==ZERO && W2L==ZERO && EPL==ZERO)
						break;
				cur_w1=INIT;
				cur_w2=INIT;
				cur_ep=INIT;
		}
		return Timer;

}

void Display(int T1,int s)
{
		int i,temp,temp1;
		fprintf(stdout,"\n Stack:%d  Total Time:%d \n \t\t\t In   Out    Waiting    Total\n",s,T1);
		fprintf(stdout,"\n-----------------------------------------------------------------------\n");
		for(i=INIT;i<MAX_STACK;i++)
		{
				temp=(Stack[i].w1_out-Stack[i].w1_in)-Stack[i].twr1;
				temp+=(Stack[i].w2_out-Stack[i].w2_in)-Stack[i].twr2;
				temp+=(Stack[i].ep_out-Stack[i].ep_in)-Stack[i].tep;
				temp1=Stack[i].twr1+Stack[i].twr2+Stack[i].tep;
				temp1+=temp;
				fprintf(stdout,"Process:%d:    %d      %d      %d    %d   \n",i+ONE,Stack[i].w1_in,Stack[i].w2_out,temp,temp1);
		}

		fprintf(stdout,"\n\n====================Detailed Timing===================================");

		for(i=INIT;i<MAX_STACK;i++)
		{
				fprintf(stdout,"\n\tProcess %d : Data",i+ONE);
				fprintf(stdout,"\n\t\tWR1 in :%d    WR1 out:%d    Total:%d    Actual:%d",Stack[i].w1_in,Stack[i].w1_out,(Stack[i].w1_out-Stack[i].w1_in),Stack[i].twr1);

				fprintf(stdout,"\n\t\tEP in  :%d    EP out:%d    Total:%d    Actual:%d",Stack[i].ep_in,Stack[i].ep_out,(Stack[i].ep_out-Stack[i].ep_in),Stack[i].tep);
				fprintf(stdout,"\n\t\tWR2 in :%d   WR2 out:%d   Total:%d    Actual:%d",Stack[i].w2_in,Stack[i].w2_out,(Stack[i].w2_out-Stack[i].w2_in),Stack[i].twr2);
		}


}
int main(int argc,char * argv[])
{
		int temp=MAX_CHAR;
		FILE * fp=NULL;
		int Time1,Time2;
			if(argc<TWO | argc>TWO)
			{
			fprintf(stdout,"\nError:Invalid Arguments\nExpected: exe input_filename\n:");
			return FAIL;
			}
		 
		fprintf(stdout,"\nProcessing Data:\n");

				fp=fopen(argv[ONE],"r");
		//fp=fopen("input","r");
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
				TICK=ONE;
				Stack=Stack2;
				Time2=Proc_Data();
				Display(Time2,TWO);
				fprintf(stdout,"\n\n\n");
				Stack=Stack1;
				Time1=Proc_Data();
				Display(Time1,ONE);
		}
}
