#include<stdio.h>
#include<unistd.h>

int main()
{
   int fds[2],pid;
   int s;
   char message[20]= "Hello mlrit";
   char buff[20];
   s = pipe(fds);
   
  pid=fork();
  if(pid==0)// child procee
  
   write(fds[1], message, sizeof(message));
   else// parent process 
   {
   read(fds[0], buff, sizeof(buff));
   printf("Reading from pipe - Message  is %s\n", buff);
   }
 
   return 0;
}

