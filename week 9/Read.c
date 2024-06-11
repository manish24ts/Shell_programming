#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#define LP "r"
int main(int argc, char *argv[])
{
	int val,fd,n,c=0,i;
	char buff[1000];
	val=mkfifo(LP,0666);
	if(val==1)
	{
		printf("FIFO IS NOT CREATED\n");
		exit(0);
	}
	fd=open(LP,O_RDONLY);
	if(fd<0)
	{
		printf("FILE OPENING ERROR\n");
		exit(0);
	}
	n=read(fd,buff,sizeof(buff));
	buff[n]='\0';
	printf("THE ORIGINAL DATA IS=%s",buff[i]);
	return 0;	
}

