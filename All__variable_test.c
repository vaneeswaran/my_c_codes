#include<stdio.h>
#include<unistd.h>
#include<malloc.h>
int global;
int global_init=0;
static int stat_global;
static int stat_global_init=0;
char *global_ptr;
char char_global_arr[]="char array";
char *char_global_ptr="char array";
int main()
{
		int local;
		int local_init=0;
		char *local_ptr;
		static int stat_local;
		static int stat_local_init=0;
		char char_local_arr[]="char array";
		char *char_local_ptr="char array";
		global_ptr=(char*)malloc(sizeof(char)*20);
		local_ptr=(char*)malloc(sizeof(char)*20);
		scanf("%d %d %d %d",&global,&global_init,&stat_global,&stat_global_init);
		scanf("%d %d %d %d",&local,&local_init,&stat_local,&stat_local_init);
		scanf("%s %s",local_ptr,global_ptr);
		printf("\nAddress of global:%X value=%d",&global,global);
		printf("\nAddress of global_init:%X value=%d",&global_init,global_init);
		printf("\nAddress of stat_global:%X value=%d",&stat_global,stat_global);
		printf("\nAddress of stat_global_init:%X value=%d",&stat_global_init,stat_global_init);

		printf("\nAddress of global_ptr:%X value=%s",&global_ptr,global_ptr);

		printf("\nAddress of char_global_ptr:%X value=%s",&char_global_ptr,char_global_ptr);
		printf("\nAddress of char_global_arr:%X value=%s",&char_global_arr,char_global_arr);

		printf("\n--Address of char_global_ptr:%X",char_global_ptr);
		printf("\n--Address of char_global_arr:%X",char_global_arr);

		printf("\nAddress of local:%X value=%d",&local,local);
		printf("\nAddress of local_init:%X value=%d",&local_init,local_init);
		printf("\nAddress of stat_local:%X value=%d",&stat_local,stat_local);
		printf("\nAddress of stat_local_init:%X value=%d",&stat_local_init,stat_local_init);


		printf("\nAddress of local_ptr:%X value=%s",&local_ptr,local_ptr);

		printf("\nAddress of char_local_arr:%X value=%s",&char_local_arr,char_local_arr);
		printf("\nAddress of char_local_ptr:%X value=%s",&char_local_ptr,char_local_ptr);

		printf("\n--Address of char_local_arr:%X",char_local_arr);
		printf("\n--Address of char_local_ptr:%X\n",char_local_ptr);
//sleep(30);

		printf("\nAddress of global:%X value=%d",&global,global);
		return 0;
}
