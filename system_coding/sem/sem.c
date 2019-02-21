#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>

char buff[100];
sem_t sem_r;//�ź�������������,��������һ�������͵���
sem_t sem_w;

void *fun1(void *arg)
{
	while(1)
	{
		sem_wait(&sem_w); //��������
		scanf("%s",buff);
		printf("write :%s\n",buff);
		sem_post(&sem_r); //��
	}
	pthread_exit(NULL);
}

void *fun2(void *arg)
{
	while(1)
	{
		sem_wait(&sem_r); //ԭ�Ӳ���(���ź�����ֵ��ȥһ����1����������Զ���ȵȴ����ź���Ϊһ������ֵ�ſ�ʼ��������Ҳ����˵��������һ��ֵΪ2���ź�������sem_wait(),�߳̽������ִ�У����ź�����ֵ������1�������һ��ֵΪ0���ź�������sem_wait()����������ͻ�صȴ�ֱ���������߳����������ֵʹ��������0Ϊֹ������������̶߳���sem_wait()�еȴ�ͬһ���ź�����ɷ���ֵ����ô�������������߳�����һ����1��ʱ���ȴ��߳���ֻ��һ���ܹ����ź���������������ִ�У���һ���������ڵȴ�״̬),������������ǰ�߳�ֱ���ź���sem��ֵ����0�����������sem��ֵ��һ������������Դ��ʹ�ú���١�����sem_trywait ( sem_t *sem )�Ǻ���sem_wait�����ķ������汾����ֱ�ӽ��ź���sem��ֵ��һ
		sleep(1);
		printf("read :%s!\n",buff);
		sem_post(&sem_w);//ԭ�Ӳ���(ͬʱ��ͬһ���ź������ӡ�1�������������߳��ǲ����ͻ�ģ���ͬʱ��ͬһ���ļ����ж����Ӻ�д����������������п��ܻ������ͻ���ź�����ֵ��Զ����ȷ�ؼ�һ����2��������Ϊ�������߳���ͼ�ı���),�����ź�����ֵ,�����߳�����������ź�����ʱ���������������ʹ���е�һ���̲߳���������ѡ�����ͬ�������̵߳ĵ��Ȳ��Ծ�����
	}
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t tid1,tid2;
	sem_init(&sem_r,0,0);
	/*���ú����Ĺ���ѡ���ָ��һ���������͵ĳ�ʼֵ��pshared�����������ź��������͡���� pshared��ֵ�ǣ����ͱ�ʾ���ǵ�ǰ��̵ľֲ��ź����������������̾��ܹ���������ź�������������ֻ�Բ��ý��̹�����ź�������Ȥ������������ܰ汾Ӱ�죩��pshared����һ�����㽫��ʹ��������ʧ��
	ԭ��int sem_init  (sem_t *__sem, int __pshared, unsigned int __value);����
semΪָ���ź����ṹ��һ��ָ�룻
pshared��Ϊ��ʱ���ź����ڽ��̼乲������ֻ��Ϊ��ǰ���̵������̹߳���
value�������ź����ĳ�ʼֵ
	*/
	sem_init(&sem_w,0,1);
	
	pthread_create(&tid1,NULL,&fun1,NULL);
	pthread_create(&tid2,NULL,&fun2,NULL);
	
	while(1);
	sem_destory(&sem_p);//�ͷ��ź���
	sem_destory(&sem_v);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
		
}