#include<stdio.h>
#define MAX_LEN 50
#define SUCCESS 0
#define FAIL 1
#define INIT 0

int n=INIT;
void Print_Arr(int n,int arr[])
{
int i=INIT;
for(i=INIT;i<n;i++)
	fprintf(stdout,"%d ",arr[i]);
fprintf(stdout,"\n");
}
void Sort_Arr(int array[], int firstIndex, int lastIndex)
{
    //declaaring index variables
	int pivotIndex, temp, index1, index2;
    if(firstIndex < lastIndex)
    {
       //assigninh first element index as pivot element
        pivotIndex = (firstIndex+lastIndex)/2;
        index1 = firstIndex;
	    index2 = lastIndex;
       //Sorting in Ascending order with quick sort
        while(index1 < index2)
       {
         while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
          {
           index1++;
           }
      while(array[index2]>array[pivotIndex])
        {
            index2--;
         }
     if(index1<index2)
        {
           //Swapping opertation
          temp = array[index1];
          array[index1] = array[index2];
          array[index2] = temp;
           }
        }
     //At the end of first iteration, swap pivot element with index2 element
     // temp = array[pivotIndex];
      //array[pivotIndex] = array[index2];
      //array[index2] = temp;
Print_Arr(n,array);
     //Recursive call for quick sort, with partiontioning
     Sort_Arr(array, firstIndex, index2-1);
     Sort_Arr(array, index2+1, lastIndex);
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
