#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
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
	printf("String is lower case string is = ");
	for(i=n-2;i>=0;i--)
	{
		if(message.mesg_text[i]>=65 && message.mesg_text[i]<=90)
		message.mesg_text[i] = message.mesg_text[i] + 32;
	}
	printf("%s",message.mesg_text);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
/*
nano LowerCaseReciever.c
cc -o ms LowerCaseReciever.c
./ms
