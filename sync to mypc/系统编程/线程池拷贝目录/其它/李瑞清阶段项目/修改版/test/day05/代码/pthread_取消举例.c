//�̵߳�ȡ��
#include "myhead.h"
void *fun(void *arg)
{
	// �Ƚ����߳����óɲ��ܱ�ȡ��
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	int i=10;
	printf("thread is start!\n");
	while(i)
	{
		i--;
		printf("now i is:%d\n",i);
		sleep(1);
	}
	// ���߳����ó��ܱ�ȡ��   
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	//pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL); ����ȡ��
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);  // ��ʱȡ��
	
	printf("really cancel!!!!\n"); // ����printf�Ǹ�ȡ���㣬������ʱȡ����ʱ���ִ��������
	printf("really  really cancel!!!!!\n");
	pthread_exit(NULL);
}
int main()
{
	pthread_t myid;
	printf("I am in main thread!\n");
	// ����һ���߳�
	pthread_create(&myid,NULL,fun,NULL);// �������̣߳�������������ִ��
	// ���ڳ�ʱ����߳�����һ��
	sleep(2);
	// ȡ���߳�
	pthread_cancel(myid);  // ������ȡ��������
	printf("main prepare exit!\n");
	// �����߳�
	pthread_join(myid,NULL);
	return 0;
	
}