#include "myhead.h"

int main()
{
	printf("father start!!!\n");
	pid_t myid=vfork();
	if(myid==0)
	{
		sleep(10);//û�ã��������ӽ�����ִ��
		printf("I am in child!!!\n");
		exit(0);
	}
	else if(myid>0)
	{
		printf("I am father!\n");
	}
	printf("father exit!!!\n");
	return 0;
}