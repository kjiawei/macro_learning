#include "myhead.h"

int main()
{
	//�ȴ����ӽ���
	pid_t myid=vfork();
	if(myid==0)
	{
		//����exec�������е�һ������
		execlp("hello","hello",NULL);
		exit(1);
	}	
	else if(myid>0)
	{
		while(1)
		{
			printf("nihao china!\n");
			sleep(1);
		}
	}
	return 0;
}