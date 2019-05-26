/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will do the following operation
#			1) Given 32 bit integer it will toggle each bit 
*/

#include<stdio.h>
#define SUCCESS 1
#define MAX_BIT 32
#define TOG_BIT(ipb,n) (ipb^= 1 << n)
#define INIT 0
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void print_byte(unsigned int byte)
{
		int i;
		fprintf(stdout,"\nBnary Form:");
		for (i = ZERO; i < MAX_BIT; i++) 
				fprintf(stdout,"%d",(((byte << i) & 0x80000000)>0)?1:0);
		fprintf(stdout,"\n");
}
int main(void)
{
		unsigned int number=INIT;
		int st_pos=INIT,end_pos=INIT;
		int i=INIT;
		fprintf(stdout,"\nEnter the 32 bit Number");
		fscanf(stdin,"%u",&number);
		print_byte(number);
		for(i=INIT;i<MAX_BIT;i++)
		{
				number=TOG_BIT(number,i);
		}
		print_byte(number);
		fprintf(stdout,"\nThe value After Toggling :%u",number);
		return SUCCESS;
}
