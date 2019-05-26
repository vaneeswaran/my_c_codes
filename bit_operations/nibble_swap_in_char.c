/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check do nibble swap in a 8 bit char 
*/
#include<stdio.h>
#define SUCCESS 0 
#define MAX_BIT_VAL 255
#define MAX_BIT 8
#define NIB(num) ( (num & 0x0F)<<4 | (num & 0xF0)>>4 )
#define INIT 0
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
void print_byte(unsigned char byte)
{
		int i;
		fprintf(stdout,"\nBnary Form:");
		for (i = ZERO; i < MAX_BIT; i++) 
				fprintf(stdout,"%d",(((byte << i) & 0x80)>0)?1:0);
		fprintf(stdout,"\n");
}
int main(void)
{
	unsigned int num = INIT;
	unsigned char result = INIT;
	fprintf(stdout,"Enter the number\n");
	fscanf(stdin,"%d",&num);
	num=((num>MAX_BIT_VAL)?MAX_BIT_VAL:num);
	print_byte(num);
	result =NIB(num);
	fprintf(stdout,"Value After nibble is %d\n",result);
	print_byte(result);
	return SUCCESS;
}


