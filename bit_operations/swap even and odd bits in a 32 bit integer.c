/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		Program to swap the odd bits to even and even to odd in a 32 bit integer and it is achieved by doing the below 
#			1) Extract Even bits from given 32 bit integer
#			2) Extract Odd bits from given 32 bit integer
#			3) Right shift even bits
#			4) Left shift odd bits
#			5) Combine even and odd bits
*/



#include<stdio.h>
#define SUCCESS 1
#define MAX_BIT 32
#define INIT 0
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
unsigned int swap(unsigned int x)
{
	unsigned int flag_even = x & 0xAAAAAAAA; // Extract even bits 
	unsigned int flag_odd = x & 0x55555555;  // Extract odd bits
    flag_even >>= 1;  // Right shift even bits
    flag_odd <<= 1;   // Left shift odd bits
	return (flag_even | flag_odd); // Combine even and odd bits
}
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
		unsigned int input=INIT,output=INIT;
		int i=INIT;
		fprintf(stdout,"\nEnter the 32 bit Number");
		fscanf(stdin,"%u",&input);
		print_byte(input);
		output=swap(input);
		fprintf(stdout,"\nValue After Swap:%u",output);
		
		print_byte(output);

		return SUCCESS;
}
