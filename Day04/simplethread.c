#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void  *ThreadFunc(void *args)
{

   int i;
   for(i=0;i<10;++i)
   {
	printf("Child thread i:%d\n",i);
   }

}

int main(){

pthread_t mythread;

void  *thread_result;


pthread_create(&mythread, NULL, ThreadFunc, NULL);

sleep(1);
return 0;



}
