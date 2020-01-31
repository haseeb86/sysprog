/* --- server.c --- */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <pthead.h>

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();
    
    int connfd = *((int*)arg);

    printf("Thread Started...\n");

    while(bContinue == 1)
    { 
               //ticks = time(NULL);
                snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", cti$
                write(connfd, sendBuff, strlen(sendBuff));
       
       //rd=read(fd1,buff,1024);
       //printf("%s\n",buff);

       //getch();
    }
    
    close(connfd);
    printf("Thread Terminated");

    return NULL;
}


int main(int argc, char *argv[])
{
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;

	char sendBuff[1025];
	time_t ticks;

	/* creates an UN-named socket inside the kernel and returns
	 * an integer known as socket descriptor
	 * This function takes domain/family as its first argument.
	 * For Internet family of IPv4 addresses we use AF_INET
	 */
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	/* The call to the function "bind()" assigns the details specified
	 * in the structure 『serv_addr' to the socket created in the step above
	 */
	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	/* The call to the function "listen()" with second argument as 10 specifies
	 * maximum number of client connections that server will queue for this listening
	 * socket.
	 */
	listen(listenfd, 10);

	while(1)
	{
	
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

		
                err = pthread_create(&tid, NULL, &doSomeThing, &connfd);

		sleep(1);
	}
}
