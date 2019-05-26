/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will remove the duplicate char in a string using linked list 
*/
#include<stdio.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>
#define MAX_CHAR 128
#define TRUE 1
#define SUCCESS 0
#define INIT 0
#define FAIL 1
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
extern int errno;
typedef struct Node
{
		char data;
		int pos;
		struct Node *next;
}NODE;
NODE *head,*tail;


void Print_List()
{

	NODE *temp=NULL;

	temp=head;
	while(temp->next!=NULL)
	{
	fprintf(stdout,"\t%c  %d\n",temp->data,temp->pos);
	temp=temp->next;
	}
			fprintf(stdout,"---------------------------------------------------------------------------------------\n");
}
void Insert_List()
{
	char temp_char=INIT;
	int temp_pos=INIT;
	int stop_flag=INIT;
		
		fprintf(stdout,"Enter the String:");
	while(TRUE)
	{
		NODE *temp=NULL;
		NODE *temp_head=NULL;
		temp=(NODE*)malloc(sizeof(NODE));
		if(temp==NULL)
			perror("Error:Insetion Failed");
		else
		{
		
		fscanf(stdin,"%c",&temp_char);
		if(temp_char=='\n' || temp_char=='\0')
			stop_flag=TRUE;	
		temp_pos++;
		temp->data=temp_char;
		temp->pos=temp_pos;
		temp->next=NULL;	
		if(head==NULL && tail==NULL)
			head=tail=temp;
		else
		{
			tail->next=temp;
			tail=tail->next;
		}
		if(stop_flag==TRUE)
			break;
		}
	}
}

void Remove_List(int N)
{
	NODE *temp=NULL;
	NODE *temp_prev=NULL;
	int i=ONE;
	temp=head;
	while(temp!=NULL && i<=N)
	{
	if(N==ONE && N==i)
	{
	if(head==tail)
	tail=NULL;
	head=temp->next;
	free(temp);
	break;
	}
	else if (temp==tail && N==i)
	{
	tail=temp_prev;
	tail->next=NULL;
	free(temp);
	}
	else if(N==i)
	{
	temp_prev->next=temp->next;
	free(temp);
	}
	temp_prev=temp;
	temp=temp->next;
	i++;
	}
}

void Check_Dup()
{
char FLAG[MAX_CHAR];
char ref=INIT;
int Test_Flag=ONE;
NODE *temp;
while(Test_Flag==ONE)
{
int i=INIT,N=ONE;
temp=head;
while(i<MAX_CHAR)
	FLAG[i++]=ZERO;
while(temp!=NULL)
	{
		Test_Flag=ZERO;
		ref=temp->data;
		if(FLAG[ref]==ZERO)
		{
		FLAG[ref]=TRUE;
		}
		else
		{
		Remove_List(N);
		Test_Flag=ONE;
		break;
		}
		N++;
		temp=temp->next;
	}
}

}
int main(void)
{
		
		head=tail=NULL;
			Insert_List();
			fprintf(stdout,"--------------------------Before Removing Duplicate Characters-------------------------\n");
			Print_List();
			Check_Dup();
			fprintf(stdout,"--------------------------After Removing Duplicate Characters-------------------------\n");
			Print_List();
			return SUCCESS;
}
