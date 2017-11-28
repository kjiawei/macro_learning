#include "myhead.h"
int i=0;
//����һ����
pthread_mutex_t  mutex;
void *fun1(void *arg)
{
	while(1)
	{
		//�߳�һ��������
		pthread_mutex_lock(&mutex); //��ռ��
		i++;
		printf("thread 1 i is:%d\n",i);
		sleep(1);
	
		pthread_mutex_unlock(&mutex);
		usleep(2000);  //��ֹ�߳�һ�ս����������޳ܵ�����
	}
	pthread_exit(NULL);
}
void *fun2(void *arg)
{
	
	while(1)
	{
		usleep(2000);
		//�̶߳���������
		pthread_mutex_lock(&mutex); 
		i--;
		printf("thread 2 i is:%d\n",i);
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}
int main()
{
	pthread_t id1;
	pthread_t id2;
	
	//��ʼ����
	pthread_mutex_init(&mutex,NULL);
	//���������߳�
	pthread_create(&id1,NULL,fun1,NULL);
	pthread_create(&id2,NULL,fun2,NULL);
	
	//
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
}