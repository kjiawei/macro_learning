#include "myhead.h"

void *fun(void *arg)
{
	printf("I am thread start!\n");
	pthread_exit("thread exit");
}
int main()
{
	void *str=NULL;
	pthread_t myid;
	pthread_attr_t myaddr;//���Խṹ��
	
	pthread_attr_init(&myaddr);//��ʼ��
	pthread_attr_setdetachstate(&myaddr,PTHREAD_CREATE_DETACHED);//���÷�������:���һ���
	
	pthread_create(&myid,&myaddr,fun,NULL);//�����߳�,��Ч����
   	pthread_join(myid,&str);//���ܻ����߳�,��ɷ����ô��벻������
	printf("thread exit msg is:%s\n",(char *)str);//��ӡ������Ϣ
	pthread_attr_destroy(&myaddr);//�߳���������
	return 0;
}