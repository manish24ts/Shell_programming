
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define LP "r"
int main(int argc, char *argv[])
{
	int fd,i;
	fd=open(LP,O_WRONLY);
	if(fd<0)
	{
		printf("FILE OPENING ERROR\n");
		exit(0);
	}
	for(i=1;i<argc;i++)
	{
		write(fd,argv[i],strlen(argv[i]));
	}
	return 0;
}

