#include "myhead.h"
/*�²�Ĵ�
I am in father process!
I am in child process!
I am still in father process!
I am father,prepare exit!
*/

/*ʵ����ȷ��
I am in father process!
I am in child process!
I am father,prepare exit!
I am still in father process!
I am father,prepare exit!
*/
int main()
{
	pid_t myid;
	int status;
	printf("I am in father process grandpa ID is:%d!\n",(int)getppid());
	printf("I am in father process ID is:%d!\n",(int)getpid());
	// �����ӽ��̣������У�
	myid=fork();
	// �ж��Ƿ����ӽ�����
	if(myid==0)
	{
		printf("I am in child process! my id is:%d\n",(int)getpid());
		printf("my father is:%d\n",(int)getppid());
		exit(0);
	}
	// ���ڸ�����
	else if(myid>0)
	{
		//sleep(2);//�������̹���2�룬��ô�ӽ��̾����㹻��ʱ��ȥ��ִ��
		printf("I am still in father process!\n");
	}
	else
	{
		printf("create child failed!\n");
	}
	printf("I am father,prepare exit!\n");
	// �����ӽ���
	wait(&status);
	//printf("child exit status value is:%d\n",WEXITSTATUS(status));
	// �ж��ӽ����Ƿ������˳�
	if(WIFEXITED(status))
		printf("child exit normal!\n");
	
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




