#include "myhead.h"

int main()
{
	int count=0;
	struct sembuf mysembuf;
	bzero(&mysembuf,sizeof(mysembuf));
	// ��ʼ���ṹ��
	mysembuf.sem_num=0; // ������������0���ź���
	mysembuf.sem_op=1;  // v ����  +1
	mysembuf.sem_flg=SEM_UNDO;
	// �����ź���
	int semid=semget((key_t)3456,1,IPC_CREAT|0777);
	if(semid==-1)
	{
		perror("create sem failed!\n");
		return -1;
	}
	// �����ź����ĳ�ֵ
	semctl(semid,0,SETVAL,0);
	while(1)
	{
		
		printf("hello world! %d\n",count++);
		sleep(2);
		// ������ź�������v����
		//v����  ������
		semop(semid,&mysembuf,1);  //  1
	}
}