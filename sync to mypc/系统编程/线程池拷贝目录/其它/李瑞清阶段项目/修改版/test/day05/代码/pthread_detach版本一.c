#include "myhead.h"

void *fun(void *arg)
{
	printf("*((pthread_t *)arg) is:%ld\n",*((pthread_t *)arg));
	// �����߳����óɿ��Է���
	pthread_detach(*((pthread_t *)arg));
	printf("I am thread start!\n");
	pthread_exit("thread exit");
}
int main()
{
	void *str=NULL;
	pthread_t myid;
	// ����һ���̣߳���������
	pthread_create(&myid,NULL,fun,(void *)(&myid));
	printf("myid is:%ld\n",myid);
	sleep(2); //�ڳ��㹻��ʱ�������߳�������
   	pthread_join(myid,&str);// �ܷ����������߳�,���ܻ��գ�ԭ�����̱߳����óɷ���ģ��ô��벻��������
	//��ӡ������Ϣ
	printf("thread exit msg is:%s\n",(char *)str);
	return 0;
}