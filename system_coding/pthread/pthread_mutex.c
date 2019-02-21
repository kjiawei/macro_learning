#include <stdio.h>
#include <pthread.h>

int g_value = 0;
pthread_mutex_t mutex;
void *thread1(void *arg)
{
    while(1)
	{
		pthread_mutex_lock(&mutex);//����
        g_value = g_value + 1;
        printf("thread1 g_value=%d\n", g_value);
        g_value = g_value + 1;
        usleep(100);
        printf("thread1 g_value=%d\n", g_value);
        usleep(100);
		pthread_mutex_unlock(&mutex);//����
    }
    pthread_exit(NULL);  
}
void *thread2(void *arg)
{
    
	while(1)
	{
			//pthread_mutex_lock(&mutex);//����
        pthread_mutex_lock(&mutex);//����
		g_value = g_value + 1;
        printf("thread2 g_value=%d\n", g_value);
        usleep(100);
        g_value = g_value + 1;
        printf("thread2 g_value=%d\n", g_value);
        usleep(100);
		pthread_mutex_unlock(&mutex);//����
			//	pthread_mutex_unlock(&mutex);//����
    }
	pthread_exit(NULL);
       
}
int main(void)
{
	pthread_t tid,tid2;
	pthread_mutex_init(&mutex,NULL);//��������ʼ��
	pthread_create(&tid,NULL,thread2,NULL);
	pthread_create(&tid2,NULL,thread1,NULL);
	
	sleep(1);
	
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	
}
