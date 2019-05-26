/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will do the following operation in a linked list
#			1) Create / Insert Linked List 
#			2) Delete Linked List 
#			3) Print Linked List 
#			4) Sort Linked List 	
#
*/
#include<stdio.h>
#include<malloc.h>
#include<errno.h>
#include<string.h>
#define TRUE 1
#define SUCCESS 0
#define INIT 0
#define MAX_BUFFER 10
#define MAX_CHAR 50
#define FAIL 1
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
extern int errno;
typedef struct Node
{
		char name[MAX_CHAR];
		int age;
		struct Node *next;
}NODE;
NODE *head,*tail;

/*struct list
  {
  struct node *head;
  struct node *tail;
  }List;*/
void Sort_List()
{

		int flag=FAIL;
		while(flag==FAIL)
		{
			NODE* temp_head=head;
			while(temp_head->next!=NULL)
			{
			if(temp_head->age > temp_head->next->age)
				{
					char temp_name[MAX_CHAR];
					int temp_age;
					strcpy(temp_name,temp_head->name);
					strcpy(temp_head->name,temp_head->next->name);
					strcpy(temp_head->next->name,temp_name);
					temp_age=temp_head->age;
					temp_head->age=temp_head->next->age;
					temp_head->next->age=temp_age;
					flag=FAIL;
					break;
				}
			else
				flag=SUCCESS;
			temp_head=temp_head->next;
			}
		}
}
void Print_List()
{

	NODE *temp=NULL;
	int i=ONE,N=INIT;
	temp=head;
	fscanf(stdin,"%d",&N);
	while(temp!=NULL)
	{
	if(i>=N)
	fprintf(stdout,"\t%s  %d\n",temp->name,temp->age);
	i++;
	temp=temp->next;
	}
}
void Insert_List()
{
	NODE *temp=NULL;
	NODE *temp_head=NULL;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	perror("Error:Insetion Failed");
	else
	{
	fscanf(stdin,"%s %d",&temp->name,&temp->age);
	temp->next=NULL;	
		if(head==NULL && tail==NULL)
		head=tail=temp;
		else
		{
		tail->next=temp;
		tail=tail->next;
		Sort_List();
		}
	}
}
void Remove_List()
{
	NODE *temp=NULL;
	NODE *temp_prev=NULL;
	int i=ONE,N=INIT;
	temp=head;
	fscanf(stdin,"%d",&N);
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

int main(void)
{
		
		head=tail=NULL;
		while(TRUE)
		{
				char opt[MAX_BUFFER];
				fscanf(stdin,"%s",&opt);

				if(!(strcmp("insert",opt)) ||  !(strcmp("Insert",opt))) 
				Insert_List();
				else if(!(strcmp("Remove",opt)) ||  !(strcmp("remove",opt))) 
				Remove_List();
				else if(!(strcmp("print",opt)) ||  !(strcmp("Print",opt))) 
				Print_List();
				else if(!(strcmp("stop",opt)) ||  !(strcmp("Stop",opt))) 
						break;
				else
						fprintf(stdout,"Invalid Command\n");


		}
		return SUCCESS;
}
