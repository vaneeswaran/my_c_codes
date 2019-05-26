/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		The below code will do the following operations using macro
#			1) Set a Bit
#			2) Clear a Bit
#			3) Toggle a Bit
#			4) Test a bit
#			5) Multiply 2 Numbers
#			6) Maximum of 2
#			7) Absolute Value
#			8) Test for Num Char 
#			9) String Compare
*/

//Header File Declaration
#include<stdio.h>
#include<string.h>

//Macro Definition

#define SET_BIT(ipb,n) (ipb|= 1 << n) //ipb is the input byte and n is the position 
#define CLR_BIT(ipb,n) (ipb &= ~(1<<n))
#define TOG_BIT(ipb,n) (ipb^= 1 << n)
#define TEST_BIT(ipb,n) (ipb&=(1<<n))
#define MUL(a,b) (a*b) 
#define FIND_MAX(a,b) ((a>b)?a:b)
#define FIND_ABS(n) ((n<0)? ((~n)+1):n)
#define FIND_AN(n) ((n>=48&&n<=57)?fprintf(stdout,"\nGiven is Numeric"):fprintf(stdout,"\nGiven is Character"))
#define STR_CMP(str1,str2) ((strcmp(str1,str2))?fprintf(stdout,"Strings are Not Equal"):fprintf(stdout,"Strings are Equal"))
#define SUCCESS 0
#define FAIL 1
#define INIT 0
#define TRUE 1
#define MAX_CHAR 50
enum numbers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
//Function Definition starts
void print_byte(unsigned char byte)
{
int i;
fprintf(stdout,"\nBinary Form:");
for (i = ZERO; i < EIGHT; i++) 
	printf("%d",(((byte << i) & 0x80)>ZERO)?ONE:ZERO);
fprintf(stdout,"\n");
}

int main(void)
{
int user_opt=INIT;//for User Option
while(TRUE)
	{
		fprintf(stdout,"\n\t1.Set a bit\n\t2.Reset a bit\n\t3.Toggle a bit\n\t4.Test a bit\n\t5.Multiply 2 Numbers\n\t6.Maximum of 2\n\t7.Absolute Value\n\t8.Test for Num Char \n\t9.String Compare\n\tOthers to exit   ");
		fscanf(stdin,"%d",&user_opt);
		if(user_opt>=ONE && user_opt <=NINE)
		{
						int no_1=INIT,no_2=INIT; //For the User input
						char str1[MAX_CHAR],str2[MAX_CHAR];
						unsigned char input_byte=INIT;
						int bit_pos=INIT;
				if(user_opt == FIVE | user_opt == SIX)
				{
						fprintf(stdout,"\nEnter Two Numbers:");
						fscanf(stdin,"%d%d",&no_1,&no_2);
				}
				else if (user_opt >=ONE && user_opt<=FOUR)
				{
						fprintf(stdout,"\nEnter A Byte and Position(1 to 8):");
						fscanf(stdin,"%d%d",&input_byte,&bit_pos);
						bit_pos-=ONE;//To make bit position more convinient for user
				}
		
		switch(user_opt)
		{
		case ONE:
			{	print_byte(input_byte);
				unsigned char output_byte=SET_BIT(input_byte,bit_pos);
				fprintf(stdout,"\nByte After Set:%d",output_byte);
				print_byte(output_byte);
				break;
			}
		case TWO:
			{
				print_byte(input_byte);
				unsigned char output_byte=CLR_BIT(input_byte,bit_pos);
				fprintf(stdout,"\nByte After Reset:%d",output_byte);
				print_byte(output_byte);
				break;
			}
		case THREE:
			{
				print_byte(input_byte);
				unsigned char output_byte=TOG_BIT(input_byte,bit_pos);
				fprintf(stdout,"\nByte After Toggle:%d",output_byte);
				print_byte(output_byte);
				break;
			}
		case FOUR:
			{
				int flag=TEST_BIT(input_byte,bit_pos);
				if(flag>ZERO)
				flag=TRUE;
				fprintf(stdout,"\nBit Test Value:%d",flag);
				break;
			}
		case FIVE:
			{
				fprintf(stdout,"\nResult is :%d",MUL(no_1,no_2));
				break;
			}
			
		case SIX:
			{
				fprintf(stdout,"\nMaximum is :%d",FIND_MAX(no_1,no_2));
				break;
			}
		case SEVEN:
			{
					
				fprintf(stdout,"\nEnter the Number:");
				fscanf(stdin,"%d",&no_1);
				fprintf(stdout,"\nAbsolute Value is :%d",FIND_ABS(no_1));
				break;
			}
		case EIGHT:
			{
			
				fprintf(stdout,"\nEnter the Character:");
				fscanf(stdin," %c",&input_byte);
				FIND_AN(input_byte);
				break;
		
			}
		case NINE:
			{
				fprintf(stdout,"\nEnter Two String");
				fscanf(stdin,"%s%s",&str1,&str2);
				STR_CMP(str1,str2);
				break;
			}
		
		}
		}
		else
			break;
			
}
return SUCCESS;
}
