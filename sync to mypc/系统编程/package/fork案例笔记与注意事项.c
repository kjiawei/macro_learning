#include "myhead.h"
//�������̵�,�ɹ���ִ��һ���ӽ�����Ĵ��루�����һ���ϰ���ִ�У�,Ȼ���ٰ����߼�ִ��һ�����

int main()
{
	int status;//�����ӽ���
	pid_t myid=fork();// �����ӽ���
	
	// �ж��Ƿ���(0)�ӽ�����
	if(myid==0)
	{printf("�����ӽ���,pid��:%d,��������:%d\n",(int)getpid(),(int)getppid());
		exit(0);//�����Է�����������;
		//_exit(0);��ˢ��IO��������ֱ���˳�������ӡ������������
		}
	else if(myid>0)
	{sleep(2);//�������̹���2�룬��ô�ӽ��̾����㹻��ʱ��ȥ��ִ��
		printf("I am still in father process!\n");}
	//else{printf("create child failed!\n");}
	printf("I am father,prepare exit!\n");
	
	wait(&status);// �����ӽ���(�����������˳��������),�����������˳�ʱ״̬��Ϣ,������������
	//waitpid(ret,&status,0);
	//����1:0  ����2:  ����3:WNOHANG
	if(WIFEXITED(status))printf("child exit normal!\n");// �������˳���Ϊ��,ʧ��-1,�ɹ���id
	//�˳�������״̬��Ϣ:WEXITSTATUS(status)
	//printf("��һ�����յ���:%d\n",WEXITSTATUS(status));
	
	return 0;//�ɷ��ں�����ִ�е����󷵻ص��������ĺ���
}
