#include "myhead.h"

void *fun(void *arg)
{
	sleep(1);
	printf("*((pthread_t *)arg) is:%ld\n",*((pthread_t *)arg));
	printf("I am thread start!\n");
	pthread_exit("thread exit");
}
int main()
{
	void *str=NULL;
	pthread_t myid;
	// ����һ���̣߳���������
	pthread_create(&myid,NULL,fun,(void *)(&myid));
	// �����߳����óɿ��Է���
	pthread_detach(myid);
	printf("myid is:%ld\n",myid);
	sleep(2); //�ڳ��㹻��ʱ�������߳�������
   	pthread_join(myid,&str);// �ܷ����������߳�,���ܻ��գ�ԭ�����̱߳����óɷ���ģ��ô��벻��������
	printf("thread exit msg is:%s\n",(char *)str);//��ӡ������Ϣ
	return 0;
}