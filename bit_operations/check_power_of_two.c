/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will check whether the given number is power of two or not 
*/

#include<stdio.h>
#define SUCCESS 1
#define MAX_BIT 32
#define INIT 0
#define POW(num) ((num!=0)?((num & (num-1))?fprintf(stdout,"\nNot Power of two\n"):fprintf(stdout,"\nPower\n")):fprintf(stdout,"\nNot Power of two\n"))
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
int main(void)
{
		unsigned int num=INIT;
		fprintf(stdout,"\nEnter the 32 bit Number");
		fscanf(stdin,"%u",&num);
		POW(num);
		return SUCCESS;
}
