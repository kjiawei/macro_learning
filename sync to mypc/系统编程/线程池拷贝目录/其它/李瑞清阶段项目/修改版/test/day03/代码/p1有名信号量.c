#include "myhead.h"
// ʹ��POSIX �����ź���ʵ��pv����
int main()
{
	sem_t *mysem;
	int count=0;
	// �½������ź���
	mysem=sem_open("abc",O_CREAT,0777,0);
	if(mysem==SEM_FAILED)
	{
		perror("create named failed!\n");
		return -1;
	}
	
	while(1)
	{
		
		printf("hello world! %d\n",count++);
		sleep(2);
		// ������ź�������v����
		//v����  ������
		sem_post(mysem);
	}
	
}