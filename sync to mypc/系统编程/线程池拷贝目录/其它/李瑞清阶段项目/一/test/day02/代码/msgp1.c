#include "myhead.h"
// ��Ϣ����
struct msg
{
	long type;
	char buf[50];
};
int main()
{
	int msgid;
	// ������Ϣ����
	if((msgid=msgget((key_t)2000,IPC_CREAT|IPC_EXCL|0777))==-1)
	{
		perror("create msg queue failed!\n");
		return -1;
	}
	struct msg sendmsg;
	bzero(&sendmsg,sizeof(sendmsg));
	printf("please input a string you want to send!\n");
	scanf("%s",sendmsg.buf);
	sendmsg.type=80;
	// ���ͳ�ʼ���õ���Ϣ
	msgsnd(msgid,&sendmsg,sizeof(struct msg),0);
	
	return 0;
	
}