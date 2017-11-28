#include "myhead.h"

int main()
{
	int count=0;
	struct sembuf mysembuf1;
	struct sembuf mysembuf2;
	bzero(&mysembuf1,sizeof(mysembuf1));
	bzero(&mysembuf2,sizeof(mysembuf2));
	mysembuf2.sem_num=1; // ������������1���ź���
	mysembuf2.sem_op=-1;  // p ����  -1
	mysembuf2.sem_flg=SEM_UNDO;
	// ��ʼ���ṹ��
	mysembuf1.sem_num=0; // ������������0���ź���
	mysembuf1.sem_op=1;  // v ����  +1
	mysembuf1.sem_flg=SEM_UNDO;
	// �����ź���
	int semid=semget((key_t)3456,2,IPC_CREAT|0777);
	if(semid==-1)
	{
		perror("create sem failed!\n");
		return -1;
	}
	// �����ź����ĳ�ֵ
	semctl(semid,0,SETVAL,0);
	semctl(semid,1,SETVAL,1);
	while(1)
	{
		// ���ź���2����p����
		semop(semid,&mysembuf2,1);
		printf("sem1 value is:%d\n",semctl(semid,0,GETVAL));
		printf("sem2 value is:%d\n",semctl(semid,1,GETVAL));
		printf("hello world! %d\n",count++);
		sleep(1);
		// ���ź���1����v����---��Ŀ����Ϊ�˽��p2���̵�����
		semop(semid,&mysembuf1,1);
	}
}