/*************************************************
 File name : linux_system_func.c
 Create date : 2019-2-11 19:04
 Modified date : 2019-2-11 19:04
 Author :jkCodic
 Email : 523090538@qq.com
 Describe:linuxϵͳ��̺���,��ϰ/����ʹ��
 ***********************************************/
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

/*****������*****/
pthread_mutex_t mutex;
void printf_char(char *string)
{
	char *p = string;
	while(*p != '\0')
	{
		fprintf(stderr,"%c",*p);
		usleep(500);
		p++;
	}
	printf("\n");
}

void *fun1(void *arg)
{
	pthread_mutex_lock(&mutex);//����
	printf_char("GSDGLOVGSDQLDSFD4GF5DF75DA5W");
	pthread_mutex_unlock(&mutex);//����
	pthread_exit(NULL);
}

void *fun2(void *arg)
{
	pthread_mutex_lock(&mutex);//����
	printf_char("sddscxlvjslejslvslflsljflseflksd");
	pthread_mutex_unlock(&mutex);//����
	pthread_exit(NULL);
}

void test_mutex(){
	pthread_t tid1,tid2;
	pthread_mutex_init(&mutex,NULL);//��������ʼ��
	pthread_create(&tid1,NULL,&fun1,NULL);
	pthread_create(&tid2,NULL,&fun2,NULL);
	sleep(2);
	pthread_mutex_destroy(&mutex);//���ٻ�����
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
/*****������*****/

/*
	�����ڴ�
	��Чֱ�Ӳ��������ڴ治��Ҫ�κεĿ���(���ں�����һ���ڴ�ӳ�䵽��������������ַ�ռ���,ֱ�Ӷ�д��������еĿռ�)
ɾ�������ڴ�
       int shmctl(int shmid, int cmd, struct shmid_ds *buf);
int shmid�����뵽���ڴ�ID
int cmd:����  IPC_RMID��ɾ����
struct shmid_ds *buf��0
*/
void test_shareMemory(){
	char buff[20];
	int shmid;
	shmid = shmget(ftok(".",1),256,IPC_CREAT | 0666);//���빲���ڴ棬ftok��ȡkeyֵ
	/*
	ԭ��int shmget(key_t key, size_t size, int shmflg);
����ֵ:�ɹ� �������뵽���ڴ�ID  ʧ�ܣ�-1
key_t key���ڴ�ļ�ֵ
size_t size����С
int shmflg��Ȩ�ޱ�־IPC_CREAT
	*/
	char *mem_p = shmat(shmid,NULL,0);//ӳ�乲���ڴ浽���̿ռ�
	/*
	void *shmat(int shmid, const void *shmaddr, int shmflg);
����ֵ���ɹ���ӳ��ĵ�ַ��
const void *shmaddr��ӳ����ʼ��ַ��
int shmflg��Ȩ�ޱ�־ 0����ɶ�����д
	*/
	bzero(buff,20);
	fgets(mem_p,256,stdin);
	shmdt(mem_p);
}

/*****��������*****/
void test_cond(){

}
/*****��������*****/

/*
�ź���(semaphore�źŵ�):��ͬ���̼��һ���������ڲ���ͬ�̼߳�ͬ���Ļ���
��ֵ�ź���:ֵΪ0��1,�뻥��������,��Դ����ʱֵΪ1,������ʱֵΪ0��
�����ź���:ֵ��0��n֮��(ͳ����Դ,ֵ���������Դ��)

�ź�������:V�ͷ���Դ,�ź���ֵ��1;P������Դ,�ź���ֵ��1(�����������˯��)
��0����:�Ȳ�����Ҳ���ͷŶ������������ֱ���ź�����ֵΪ0
*/
void test_sem(){

}

/*
��Ϣ����:��Ϣ���б�,�û���������Ϣ�����������Ϣ����ȡ��Ϣ(��������������/����),IPC����һ��,��ID��Ψһ��ʶ(ʹ��ʱ����)
�鿴 ipcs -q,ɾ�� ipcrm -q msgid /  ipcrm -Q Key	
*/
#define SIZE 64
//���ݽ��սṹ��
struct msg_rv
{
	int mtype;
	char msg[50];
};

//���ݷ��ͽṹ��
struct msg_snd
{
	int mtype;
	char msg[50];
};

void test_msgQueue(){
	struct msg_rv data;
	struct msg_snd snddata;
	data.mtype = 1;
	int msgID = msgget((key_t)2058,IPC_CREAT | 0666);//��ȡ��Ϣ���е�ID,ԭ��int msgget(key_t key, int flag);key:����Ϣ���й�����keyֵ,flag����Ϣ���еķ���Ȩ��;�ɹ�:��Ϣ����ID,����:-1 
	if(msgID == -1) return -1;
	char buff[50];
	while(1){
		data.mtype = 89;
		snddata.mtype = 88;
		if(msgrcv(msgid,(void *)&data,sizeof(struct msg_rv),data.mtype,0)==-1) return -1;
		/*
		ԭ��  int msgrcv(int msgid,  void* msgp,  size_t  size,  long msgtype,  int  flag);//��Ϣ����
msqid����Ϣ���е�ID,msgp��������Ϣ�Ļ�����,size��Ҫ���յ���Ϣ���ֽ���
msgtype: 0��������Ϣ�����е�һ����Ϣ��
		����0��������Ϣ�����е�һ������Ϊmsgtyp����Ϣ.
		С��0��������Ϣ����������ֵ��С��msgtyp�ľ���ֵ������ֵ����С����Ϣ��
flag:0��������Ϣ������һֱ���� IPC_NOWAIT����û����Ϣ�����̻���������ENOMSG,����ֵ	�ɹ������յ�����Ϣ�ĳ��� ����-1
		*/
		if(strncmp(data.msg,"end",3)==0) break;
		bzero(buff,50);
		fgets(buff,50,stdin);
		strcpy(snddata.msg,buff);
		if(strncmp(snddata.msg,"end",3)==0) break;
		msgsnd(msgid,(void *)&snddata,strlen(buff)+4,0);//��Ϣ����
		/*
		ԭ��int msgsnd(int msqid, const void *msgp, size_t size, int flag);msqid����Ϣ���е�ID,msgp��ָ����Ϣ��ָ�롣
������Ϣ�ṹmsgbuf���£�struct msgbuf
{
	long mtype;        //��Ϣ���� 
	char mtext[N];     //��Ϣ����
}��
size�����͵���Ϣ���ĵ��ֽ���
flag��  IPC_NOWAIT  ��Ϣû�з�����ɺ���Ҳ����������,0��ֱ��������ɺ����ŷ��� ����ֵ	�ɹ���0,����-1
		*/
	}
	msgctl(msgid,IPC_RMID,0);//������Ϣ���ж��� 
	/*ԭ��	int msgctl ( int msgqid, int cmd, struct msqid_ds *buf );	
msqid����Ϣ���еĶ���ID
cmd��	IPC_STAT����ȡ��Ϣ���е����ԣ������䱣����bufָ��Ļ������С�
	IPC_SET��������Ϣ���е����ԡ����ֵȡ��buf������
	IPC_RMID����ϵͳ��ɾ����Ϣ���С�
buf����Ϣ���л�����
����ֵ	�ɹ���0 ����-1*/
}
/*****��Ϣ����*****/

/*
 	a:��pipe����һ�������ܵ�֮�����������������ӽ���A��B��
 	b: �ӽ���A �����ܵ�д��һ��hello ����˳��� --------д fd[1]
  	c: �ӽ���B����Aд������ݣ������ܵ���д��hello world ----��fd[0] дfd[1]
  	d: �����̶�ȡ���ܵ��е����ݲ���ӡ ----��fd[0]

	  ����ܵ�����������Ѿ�д���ˣ������������ֱ�����ݱ����������ܼ���д��
		�����ܵ���д�������ܱ�֤���ݵ�ԭ���ԣ������ԣ�
	�������ܵ����ļ�������read()/write()/close()
			    ���ǲ���lseek���᷵��ʧ��
			    pipe()�򿪲����������ܵ����Ѿ����úô򿪷�ʽ�����ܸ��ġ�
			    �����ܵ�ֻ�����ڽ����У����̽���Ҳ��֮��ʧ
		���ޣ�ֻ������Ե�����У����ݵ������Բ��ܱ�֤
	���ڹܵ������ڹ���Ŀ¼��ȥ��������
*/
void test_pipe(){
	int fd[2];//��д�˵�������
	char buf[100];
	const int size=100;
	if(pipe(fd)==-1) perror("pipe error!\n");//pipe()������fork()֮ǰ���ܱ�֤��Ե����ʹ��ͬһ���ܵ�
	else
	{
		pid_t pid1 = fork();
		if(pid1 == -1) perror("fork1 error!\n");
		else if(pid1 == 0)
		{
			close(fd[0]);
			printf("child1 start write...\n please input:");
			scanf("%d",buf);
			write(fd[1],buf,size);
			close(fd[1]);
		}
		else if(pid1 > 0)
		{
			waitpid(pid1,NULL,0);
			pit_t pid2 = fork();
			if(pid2 == -1) perror("fork2 error!\n");
			else if(pid2 == 0)
			{
				printf("child2 start read...\n ");
				read(fd[0],buf,size);
				close(fd[0]);
				printf("child2 read:%s\n",buf);
				
				printf("child2 start write...\n please input");
				scanf("%s",buf);
				write(f[1],buf,size);//���д�˹ر��ˣ��������̷���,������˹ر��ˣ��ڵ���writeʱ���ں˻����һ��SIGPIPE��write:Broken pipe��
				prinf("child2 finish to write!\n");
				close(fd[1]);
			}
			else if(pid2 > 0)
			{
				waitpid(pid2,NULL,0);
				close(fd[1]);
				printf("parent start read...\n ");
				read(fd[0],buf,size);//�������������ģ���ȵ�������д��ŷ���
				close(fd[0]);//�ڶ���д�˲�ʹ��ʱҪ��close�ر�
				printf("parent read:%s\n",buf);
			}
		}
	}
}

/*
�����ܵ�:�������������̼�ͨ��
1���������������ģ���ȵ�������д��ŷ��أ���������
		2�����д�˹ر��ˣ����˵�read��û�еȴ��ı��룬��ֱ��pass
		3��д��Ҳ���������ܵ������Ѿ�д���ˣ������������ܹ���֤���ݵ�ԭ���ԡ������ԣ�

*/
#define FIFO "myfifo1"
#define FIFO2 "myfifo2"

void test_fifoWrite()
{
	int my_fd,fd;
	char w_buff[30];

	bzero(w_buff,30);
	if(access(FIFO2,F_OK)==-1)
	{
		my_fd = mkfifo(FIFO2,0664);
		if(my_fd == -1)
		{
			perror("failed!\n");
			return -1;
		}
	}
	fd = open(FIFO2,O_WRONLY);
	if(fd==-1)
	{
		printf("open fifo file failed!\n");
		exit(0);
	}
	while(1)
	{
		bzero(w_buff,30);
		fgets(w_buff,30,stdin);
		write(fd,w_buff,strlen(w_buff));
	}
	close(fd);
}
void test_fifoRead()
{
	int my_fd,fd;
	char r_buff[30];

	bzero(r_buff,30);
	if(access(FIFO,F_OK)==-1)//ȷ���ļ����ļ��еķ���Ȩ�ޡ��������ĳ���ļ��Ĵ�ȡ��ʽ������˵��ֻ����ʽ��ֻд��ʽ�ȡ����ָ���Ĵ�ȡ��ʽ��Ч����������0������������-1
	{
		my_fd = mkfifo(FIFO,0664);
		if(my_fd == -1)
		{
			perror("failed!\n");
			return -1;
		}
	}

	fd = open(FIFO,O_RDONLY);
	if(fd==-1)
	{
		printf("open fifo file failed!\n");
		exit(0);
	}
	//fgets(w_buff,30,stdin);
	while(1)
	{
		bzero(r_buff,30);
		read(fd,r_buff,sizeof(r_buff));
		printf("r_buff = %s\n",r_buff);
	}

	close(fd);
}
/*�����ܵ�*/

/*
�ź�signal

*/

void f(int sig)
{
	printf("sig = %d\n",sig);
}

void test_signal(){
	sigset_t set;//��ʼ��һ���źż�
	printf("pid = %d\n",getpid());
	signal(SIGKILL,f);
	printf("signal wait:\n");
	sigemptyset(&set);//����źż�
	sigaddset(&set,SIGKILL);//����źż�
	sigaddset(&set,SIGHUP);//����źż�

	//�����źż�
	sigprocmask(SIG_BLOCK,&set,NULL);

	int i = 20;
	while(i)
	{
		printf("i = %d\n",i);
		sleep(1);
		i--;
	}
	//����ź�����
	sigprocmask(SIG_UNBLOCK,&set,NULL);
}

int main()
{
	test_pipe();
		
	return 0;
	
}