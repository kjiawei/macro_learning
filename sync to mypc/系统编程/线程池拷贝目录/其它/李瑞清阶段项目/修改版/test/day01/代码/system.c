#include "myhead.h"

int main()
{
	//�ȴ����ӽ���
	pid_t myid=vfork();
	if(myid==0)
	{
		//����system�е�һ������
		system("/mnt/hgfs/share/hello");
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