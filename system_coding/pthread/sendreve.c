#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <pthread.h>

//���ݽ��սṹ��
struct msg_rv
{
	int mtype;
	char msg[50];
	
};

//���ݷ��ͽṹ��
struct msg_snd
{
	int mtype;
	char msg[50];
};


int msgid;

//�߳̽�����Ϣ����
void *send_fun(void *arg)
{
	struct msg_snd snddata;
	char buff[50];
	
	snddata.mtype = 88;
	
	while(1)
	{
		bzero(buff,50);//buff���
		printf("please input your data:\n");
		fgets(buff,50,stdin);//�Ӽ��̻�ȡ����
		strcpy(snddata.msg,buff);//��buff���ݸ��Ƶ�Ҫ���͵���Ϣ��
		printf("data = %s\n",snddata.msg);
		if(strncmp(snddata.msg,"end",3)==0)
			break;
		msgsnd(msgid,(void *)&snddata,strlen(buff)+4,0);//�õ���ֵ���ͳ�ȥ	
	}
	pthread_exit(NULL);
}


int main(void)
{
	pthread_t pthread_id;//�߳�ʶ�����
	
	
		//��ȡmsgid
	msgid = msgget((key_t)123,IPC_CREAT|0666);
	if(msgid == -1)
	{
		printf("msgid failed!\n");
		return -1;
	}
	
	//�����̷߳��ͺ���
	pthread_create(&pthread_id,NULL,&send_fun,NULL);
	
	//������սṹ��Խ�
	struct msg_rv rvdata;
	rvdata.mtype = 89;
	while(1)
	{
		//������Ϣ������Ϣ
		if(msgrcv(msgid,(void *)&rvdata,sizeof(struct msg_rv),rvdata.mtype,0)==-1)
		{
			printf("msgsnd failed!\n");
			return -1;
		}
		printf("receive data:%s\n",rvdata.msg);
		if(strncmp(rvdata.msg,"end",3)==0)
			break;
		
	}
	
	pthread_join(pthread_id,NULL);
		//������Ϣ����
	msgctl(msgid,IPC_RMID,0);
	
	return 0;
}