#include "myhead.h"
int i=100;
// �̵߳Ĺ��ܺ���
void *sub(void *arg)
{
	while(1)
	{
		i--;
		printf("thread i is:%d\n",i);
		sleep(1);
	}
}
int main()
{
	pthread_t threadid;
	printf("I am in main thread!\n");
	// ����һ���߳�
	pthread_create(&threadid,NULL,sub,NULL);
	// ���߳��ж�i��һ
	while(1)
	{
		i++;
		printf("main i is:%d\n",i);
		sleep(1);
	}
	return 0;
	
}