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
	// �������Խṹ�����
	pthread_attr_t myaddr;
	// ��ʼ���ñ���
	pthread_attr_init(&myaddr);
	// ���÷�������   �߳̿��Է���
	pthread_attr_setdetachstate(&myaddr,PTHREAD_CREATE_DETACHED);
	// ����һ���̣߳��������飬�����õ�������Ч
	pthread_create(&myid,&myaddr,fun,NULL);
   	pthread_join(myid,&str);// �ܷ����������߳�,���ܻ��գ�ԭ�����̱߳����óɷ���ģ��ô��벻��������
	//��ӡ������Ϣ
	printf("thread exit msg is:%s\n",(char *)str);
	//�߳����Ե�����
	pthread_attr_destroy(&myaddr);
	return 0;
}