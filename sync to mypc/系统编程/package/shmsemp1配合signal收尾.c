#include "myhead.h"
static char *p;
static int myshmid;
static int semid;

void over(int sig)
{
	// ��������ڴ��ӳ��
	shmdt(p);
	// ɾ�������ڴ�
	shmctl(myshmid,IPC_RMID,NULL);
	// ɾ���ź���
	semctl(semid,0,IPC_RMID);
	semctl(semid,1,IPC_RMID);
	exit(0);
}
int main()
{
	// �����ź��������Ľṹ��
	struct sembuf mybuf;
	struct sembuf mybuf1;
	// ��սṹ��
	bzero(&mybuf,sizeof(mybuf));
	bzero(&mybuf1,sizeof(mybuf1));
	// ��ʼ���ýṹ������еĳ�Ա
	// ȷ�����ĸ��ź�������pv����
	mybuf.sem_num = 0;
	// ȷ��������p��������v����
	mybuf.sem_op = -1;  //p����
	mybuf.sem_flg = SEM_UNDO;
	
	// ��ʼ���ýṹ������еĳ�Ա
	// ȷ�����ĸ��ź�������pv����
	mybuf1.sem_num = 1;
	// ȷ��������p��������v����
	mybuf1.sem_op = 1;  //v����
	mybuf1.sem_flg = SEM_UNDO;
    signal(SIGINT,over);
	//�����ź���,����
	semid = semget((key_t)1234,2,IPC_CREAT|IPC_EXCL|0777);
	if(semid == -1&&errno==EEXIST)
	{
		perror("create sem faied!\n");
		return -1;
	}
	// ���ź�����ֵ
	semctl(semid,0,SETVAL,1);
	semctl(semid,1,SETVAL,0);
	// ���������ڴ�
	myshmid = shmget((key_t)100,1024,IPC_CREAT|IPC_EXCL|0777);
	if(myshmid == -1)
	{
		perror("creat shm error!\n");
		return -1;
	}
	// ӳ�乲���ڴ浽����
	p = (char *)shmat(myshmid,NULL,0);
	while(1)
	{
		//��p1���̲�������p2�����������ź���2����  ���ź�1����p����  ������
		semop(semid,&mybuf,1); 
		printf("the message from p2 is:%s\n",p);	
		printf("please input a message!\n");
		fgets(p,50,stdin);   
		// �����p2������  �ź���2����v����
		semop(semid,&mybuf1,1);   
	}
	return 0;
}