#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#inlcude<String.h>
#define MAX 1000
struct mesg_buffer
{
	long mesg_type;
	char mesg_text[1000];
}message;
int main()
{
	key_t key;
	int msgid,n,i;
	key = ftok("progfile",65);
	msgid = msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("DATA RECEIVED IS: %s \n",message.mesg_text);
	n = strlen(message.mesg_text);
	printf("Reverese of string is = ");
	for(i=n-2;i>=0;i--)
	printf("%c",message.mesg_text[i]);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
/*
nano ReverseReciever.c
cc -o ms ReverseReciever.c
./ms
