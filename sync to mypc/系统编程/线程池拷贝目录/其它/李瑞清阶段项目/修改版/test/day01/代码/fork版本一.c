#include "myhead.h"
/*�²�Ĵ�
I am in father process!
I am in child process!
I am still in father process!
I am father,prepare exit!
*/

/*ʵ����ȷ��
I am in father process!
I am still in father process!
I am father,prepare exit!
gec@ubuntu:/mnt/hgfs/share$ I am in child process!
I am father,prepare exit!
*/
int main()
{
	pid_t myid;
	printf("I am in father process!\n");
	// �����ӽ��̣������У�
	myid=fork();
	// �ж��Ƿ����ӽ�����
	if(myid==0)
	{
		printf("I am in child process!\n");
	}
	else if(myid>0)
	{
		printf("I am still in father process!\n");
	}
	else
	{
		printf("create child failed!\n");
	}
	printf("I am father,prepare exit!\n");
	return 0;
}
/*
���ڸ��׵Ĵ��룺
   printf("I am in father process!\n");
   printf("I am still in father process!\n");
   printf("I am father,prepare exit!\n");
���ڶ��ӵĴ��룺
   printf("I am in child process!\n");
   printf("I am in father process!\n"); ���ܸ��Ƹ��׵ģ���Ϊ������֮ǰ�Ѿ�����
   printf("I am still in father process!\n");���ܸ��Ƹ��׵ģ��ϰֶ���
   printf("I am father,prepare exit!\n");
*/




