	���ź�ģ��˾����ƱԱ�������ӽ��̴�����ƱԱ�������̴���˾����
		1����ƱԱ��׽SIGINT(������)����SIGUSR1 ��˾����˾����׽��SIGUSR1 ��

�ź��ӡ��move to next station��
		2: ��ƱԱ��׽SIGQUIT(����վ)����SIGUSR2 ��˾����˾����׽��SIGUSR2 ��

�ź��ӡ��stop the bus��
		3: ˾������SIGTSTP��������վ������SIGUSR1����ƱԱ��
		   ��ƱԱ��׽��SIGUSR1�źź��ӡ��all get off the bus����ȫ�����̽���	
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t pid ;
int flag = 1;  //����  ���Ƹ������е���ѭ��
void sig1(int sig)
{
	printf("move to next station  \n");
}

void sig2(int sig)
{
	printf("stop the bus  \n");
}

void stop(int sig)
{
	printf("all get off the bus  \n");
	exit (0);
}

void quit(int sig)
{
	if(sig==SIGINT)	
		kill(getppid(),SIGUSR1);
	else if(sig==SIGQUIT)
		kill(getppid(),SIGUSR2);
//	printf("catch %d sig in child\n",sig);
}

void end(int sig)
{
	kill(pid,SIGUSR1);
	flag = 0;
}

int main(void)
{
	pid = fork();
	
	if(pid < 0)
	{
		printf("failed! \n");
	}
	else if(pid == 0)// ��ƱԱ
	{
		signal(SIGTSTP,SIG_IGN);
		signal(SIGINT,quit);
		signal(SIGQUIT,quit);
		signal(SIGUSR1,	stop);
		while(1){			
			while(-1 != pause());
		}
		
	}
	else//˾�� 
	{
		signal(SIGTSTP,end);
		signal(SIGQUIT,SIG_IGN);
		signal(SIGINT,SIG_IGN);
		signal(SIGUSR1,sig1);
		signal(SIGUSR2,sig2);
		while(flag){
			while(-1 != pause());
		}	
		wait(NULL);
		return 0;
	}
}