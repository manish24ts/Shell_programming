#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#define FIFO_PATH "/tmp/myfifo" // Path to the named pipe
int main() {
   int  pid, fd;
   char message[] = "Hello mlrit\n";
      char buff[100];
   // Create the named pipe
   mkfifo(FIFO_PATH, 0666);
   // Fork a child process
   pid = fork();
    if (pid == 0)
    {
      // Child process (writer)
      fd = open(FIFO_PATH, O_WRONLY);
      write(fd, message, strlen(message) + 1);
   printf("Message sent: %s", message);
   close(fd);
     
   }
   else
   {
      // Parent process (reader)
      fd = open(FIFO_PATH, O_RDONLY);
      read(fd, buff, sizeof(buff));
   printf("Messege received: %s", buff);
   close(fd);
   }
   return 0;
}

