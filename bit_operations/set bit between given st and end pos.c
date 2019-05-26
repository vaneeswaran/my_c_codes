/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will do the following operation
#			1) Given 32 bit integer it will set the bit between given start and end position and clear the rest 
*/

#include<stdio.h>
#define SUCCESS 1
#define MAX_BIT 32
#define SET_BIT(ipb,n) (ipb|= 1 << n) //ipb is the input byte and n is the position 
#define CLR_BIT(ipb,n) (ipb &= ~(1<<n))
#define INIT 0
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void print_byte(unsigned int byte)
{
		int i;
		fprintf(stdout,"\nBinary Form:");
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
		fscanf(stdin,"%u",&input);
		fprintf(stdout,"\nEnter the Starting and Ending Position");
		fscanf(stdin,"%d%d",&st_pos,&end_pos);
		st_pos-=ONE;
		end_pos-=ONE;
		print_byte(input);
		for(i=INIT;i<MAX_BIT;i++)
		{
				number=(i>=st_pos && i<=end_pos)?SET_BIT(number,i):CLR_BIT(number,i);
		}
		print_byte(number);
		fprintf(stdout,"\nThe value is :%u",number);
		return SUCCESS;
}
