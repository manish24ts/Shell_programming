#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 1000
struct mesg_buffer
{
	long mesg_type;
	char mesg_text[1000];
}message;
int main()
{
	key_t key;
	int msgid;
	key = ftok("progfile",65);
	msgid = msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("DATA RECEIVED IS: %s \n",message.mesg_text);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
/*
nano Reciever.c
cc -o ms Reciever.c
./ms
