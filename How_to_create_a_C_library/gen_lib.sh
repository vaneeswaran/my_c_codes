# Read Me:
#	Coded By:
#                Name:Vaneeswaran N
#                www.vaneeswaran.com
#	Description : 
#		Sample project to demonstrate how to write a C library , build as a shared library and use it 
#      	This file gen_lib.sh will compile all files and create a shared library
#
#$1 - main program $2 Library name
lib_path=`pwd`
gcc -c -fpic $2.c
gcc -shared -o lib$2.so $2.o
gcc -L$lib_path -o final $1.c -l$2
#gcc -L/home/team33/Vaneeswaran/Library -Wall -o final $1.c -l$2
