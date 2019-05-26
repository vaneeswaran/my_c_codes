/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will do the following operation
#			1) Print the 32 bit integer in binary format 
#           2) Print the number of zero's and one's  
*/
#include<stdio.h>
#define SUCCESS 0
#define INIT 0
#define MAX_BIT 32
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void print_byte(unsigned int byte)
{
		int i;
		int flag_zero=INIT,flag_one=INIT;
		fprintf(stdout,"\nBnary Form:");
		for (i = ZERO; i < MAX_BIT; i++) 
		{
				fprintf(stdout,"%d",(((byte << i) & 0x80000000)>0)?1:0);
				(((byte << i) & 0x80000000)>0)?flag_one++:flag_zero++;
		}
		fprintf(stdout,"\n Zero's=%d One's=%d",flag_zero,flag_one);
		fprintf(stdout,"\n");
}

int  main(void)
{
		unsigned int input=INIT;
		fprintf(stdout,"\nEnter the 32 bit Number");
		fscanf(stdin,"%u",&input);
		print_byte(input);
		return SUCCESS;
}
