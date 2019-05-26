#include<stdio.h>
#define MAX_LEN 50
#define SUCCESS 0
#define FAIL 1
#define INIT 0

int n=INIT;

void Print_Arr(int arr[])
{
int i=INIT;
for(i=INIT;i<n;i++)
	fprintf(stdout,"%d ",arr[i]);
fprintf(stdout,"\n");
}
int check_array(int arr[])
{
int i;
for(i=0;i<n-1;i++)
	if(arr[i]>arr[i+1])
	return FAIL;
return SUCCESS;
		
}

void swap(int arr[], int i, int j)
{	
		int temp;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
}
void Sort_Arr(int array[], int DOWN, int UP)
{
		int tmp_DOWN, tmp_UP, A;
		if(DOWN >= UP) return;
		tmp_DOWN = DOWN;
		tmp_UP = UP;
		A = array[(DOWN + UP) /2];
		while(tmp_DOWN <= tmp_UP) {
				while(array[tmp_DOWN] < A) tmp_DOWN++;
				while(array[tmp_UP] > A) tmp_UP--;
				if(tmp_DOWN <= tmp_UP) {
						swap(array,tmp_DOWN,tmp_UP);
						tmp_DOWN++; tmp_UP--;
				}
		}
		Print_Arr(array);
		if (check_array(array)==FAIL)
		{
		Sort_Arr(array,DOWN,tmp_UP);
		Sort_Arr(array,tmp_DOWN,UP);
		}
}


int main(void)
{
int arr[MAX_LEN];
int i=INIT;
fprintf(stdout,"\nEnter the data:");
fscanf(stdin,"%d",&n);

for(i=INIT;i<n;i++)
	fscanf(stdin,"%d",&arr[i]);
Sort_Arr(arr,0,n-1);
return SUCCESS;
}
