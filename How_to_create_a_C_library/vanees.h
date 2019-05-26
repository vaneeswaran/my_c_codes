/*Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		Sample project to demonstrate how to write a C library , build as a shared library and use it 
#      	This file vanees.h defines the  function used in  the shared library
*/
#ifndef VANEES_H
#define VANEES_H

/*
	Name:String_Create
	Argument: Size of the memory  to be allocated for the string
    Return Type:Dynamically allocates memory and return the base address,NULL if malloc failed
	Usage: Used top allocate memory for a string
*/
char *String_Create(int Str_Len);

/*
	Name:String_Delete
	Argument: Base Pointer of the Dynamically Allocated Memory for the string 
	Return Type:0 for SUCCESS  1 for FAIL
	Usage:To free the memory which is linked with the program 
*/
void String_Delete(char *String);

/*
	Name:String_Reverse
	Argument: Base Pointer of the Dynamically Allocated Memory for the string 
	Return Type:void
	Usage:To reverse  the content of the string  
*/
void String_Reverse(char *String);

/*
	Name:Mem_Check
	Argument: Base Pointer of the two array which is having allocated and freed nenory address 
	Return Type:int Indiacating Memory Leak is there or not
	Usage:To reverse  the content of the string  
*/
int Mem_Check();

#endif
